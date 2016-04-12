#include "Emitter.h"
#include "DDSTextureLoader.h"
#include "DrawData2D.h"
#include "GameData.h"
#include "helper.h"

Emitter::Emitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, string _particleName) : ImageGO2D(_fileName, _GD)
{
	
	//Populates the myParticles list based on the numParticles defined by the user
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
	//De-populates the list once the Emitter falls out of scope

	for (Particle* particle : myParticles)
	{
		delete particle;
	}

}

void Emitter::Tick(GameData* _GD)
{

	//Calculates the time taken based on the delta time
	time += _GD->m_dt;

	switch (_GD->m_GS)
	{

	case GS_PLAY_MAIN_CAM:
	{

		//Mouse controls for the Emitter
		float speed = 0.3f;

		m_pos.x += speed * _GD->m_mouseState->lX;
		m_pos.y += speed * _GD->m_mouseState->lY;

		break;
	}
	}

	//Ticks all the particles that are alive in the list
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
	//Draws each particle in the list that is alive
	for (Particle* particle : myParticles)
	{
		if (particle->isAlive())
		{
			particle->draw(_DD);

		}
	}

	ImageGO2D::Draw(_DD);

}

