#include "SprayEmitter.h"

SprayEmitter::SprayEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, float _spread, string _particleName) :
				Emitter(_fileName, _GD, _numParticles, _rate, _life, _speed, _particleName)
{
	spawnTimer = 0;
	spread = _spread;
}



void SprayEmitter::Tick(GameData* _GD)
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
				/*srand(time(NULL));*/
				
				float randomXOffset = (rand() % (int)spread) - spread/2.f;
				//float randomYOffset = 0; // rand() % 10;

				Vector2 particlePos = m_pos;

				//Sets the direction of travel of the particle to downwards

				Vector2 particleDir = Vector2(0, 1);

				//Sets the direction of travel for the particle

				particlePos = Vector2::Transform(particlePos, m_worldMat);
				//particleDir = Vector2::Transform(particleDir, m_worldMat) - m_pos;
				particleDir = Vector2::Transform(particleDir, Matrix::CreateRotationZ(randomXOffset * 3.142f / 180.0f));
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
	Emitter::Tick(_GD);

}



