#include "StreamEmitter.h"

bool compareParticles(const Particle* _first, const Particle* _second)
{
	return _first->getLifeLeft() < _second->getLifeLeft();
}

StreamEmitter::StreamEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, string _particleName) : 
				Emitter(_fileName, _GD, _numParticles, _rate, _life, _speed, _particleName)
{
	spawnTimer = 0;
}

void StreamEmitter::Tick(GameData* _GD)
{
	spawnTimer += _GD->m_dt;
	//Loads in particles

	while (spawnTimer > 1.f / rate)
	{
		bool particleSpawned = false;
		for (Particle* particle : myParticles)
		{
			if (!particle->isAlive())
			{
				Vector2 particlePos = m_pos;

				//Sets the direction of travel of the particle to downwards

				Vector2 particleDir = Vector2(0, 1);

				//Sets the direction of travel for the particle

				particlePos = Vector2::Transform(particlePos, m_worldMat);
				particlePos.Normalize();
				particleDir.Normalize();
				particle->Spawn(life, m_pos, particleDir);
				particleSpawned = true;
				spawnTimer -= 1.f / rate;
				break;
			}
		}
		break;
	}
	myParticles.sort(compareParticles);
	Emitter::Tick(_GD);

}