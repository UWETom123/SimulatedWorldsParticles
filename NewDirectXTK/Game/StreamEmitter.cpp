#include "StreamEmitter.h"

//Compares particles based on the amount of lifetime remaining
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

	while (spawnTimer > 1.f / rate)
	{
		bool particleSpawned = false;
		//Iterates through the particle list 
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
				//Spawn the particle with the values calculated above

				particle->Spawn(life, m_pos, particleDir);
				particleSpawned = true;
				spawnTimer -= 1.f / rate;
				break;
			}
		}
		break;
	}
	//Sort the particles using the function declared above to make sure particles are being added and removed in the correct order
	myParticles.sort(compareParticles);
	Emitter::Tick(_GD);

}