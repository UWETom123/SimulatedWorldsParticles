#include "Emitter.h"
#include "DDSTextureLoader.h"
#include "DrawData2D.h"
#include "GameData.h"
#include "helper.h"

Emitter::Emitter(string _fileName, ID3D11Device* _GD, int _numParticles, string _particleName) : ImageGO2D(_fileName, _GD)
{
	
	for (int i = 0; i < _numParticles; i++)
	{
		myParticles.push_back(new Particle(_particleName, _GD));
	}

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
	switch (_GD->m_GS)
	{

	case GS_PLAY_MAIN_CAM:
	{

		float speed = 0.3f;
		
		m_pos.x += speed * _GD->m_mouseState->lX;					
		m_pos.y += speed * _GD->m_mouseState->lY;
							  
		break;
	}

		GameObject2D::Tick(_GD);
	}

	//Loads in particles

		for (Particle* particle : myParticles)
		{
			if (!particle->isAlive())
			{
				Vector2 particlePos = m_pos;
				Vector2 particleDir = Vector2::One;

				//Sets the direction of travel for the particle

				particlePos = Vector2::Transform(particlePos, m_worldMat);
				particleDir = Vector2::Transform(particleDir, m_worldMat) - m_pos ;
				particleDir.Normalize();
				particlePos.Normalize();
				particle->Spawn(3.0f, m_pos, particleDir);

				
			}
		}

		for (Particle* particle : myParticles)
		{
			if (particle->isAlive())
			{
				particle->tick(_GD);

			}

		}

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

