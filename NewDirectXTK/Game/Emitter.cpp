#include "Emitter.h"
#include "DDSTextureLoader.h"
#include "DrawData2D.h"
#include "GameData.h"
#include "helper.h"

Emitter::Emitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, string _particleName) : ImageGO2D(_fileName, _GD)
{
	
	for (int i = 0; i < _numParticles; i++)
	{
		myParticles.push_back(new Particle(_particleName, _speed, _GD));
	}

	life = _life;
	rate = _rate;
	time = 0;

}

Emitter::~Emitter()
{

	for (Particle* particle : myParticles)
	{
		delete particle;
	}

}

void Emitter::Tick(GameData* _GD)
{
	time += _GD->m_dt;

	switch (_GD->m_GS)
	{

	case GS_PLAY_MAIN_CAM:
	{

		//Speed of mouse movement
		float speed = 0.3f;

		m_pos.x += speed * _GD->m_mouseState->lX;
		m_pos.y += speed * _GD->m_mouseState->lY;

		break;
	}
	}

	//Loads in particles

	

	for (Particle* particle : myParticles)
	{
		if (particle->isAlive())
		{
			particle->tick(_GD);

		}
	}
	ImageGO2D::Tick(_GD);
}

void Emitter::Draw(DrawData2D* _DD)
{
	for (Particle* particle : myParticles)
	{
		if (particle->isAlive())
		{
			particle->draw(_DD);

		}
	}

	ImageGO2D::Draw(_DD);

}

