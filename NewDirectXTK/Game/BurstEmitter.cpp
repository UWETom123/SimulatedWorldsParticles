#include "BurstEmitter.h"
#include "AntTweakBar.h"

//BurstEmitter emits particles in a pulse and inherits from the Emitter class
//It has modified logic inside the tick function that will cause particles to emitted in bursts depending on the values passed in

BurstEmitter::BurstEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, int _numParticlesPerBurst,
float _burstRate, float _life, float _speed, float _spread, string _particleName) :
Emitter(_fileName, _GD, _numParticles, _burstRate, _life, _speed, _particleName)
{
	spawnTimer = 0;
	burstRate = _burstRate;
	numParticlesPerBurst = _numParticlesPerBurst;
	spread = _spread;
	numParticles = _numParticles;
	life = _life;
	speed = _speed;

	//Setup Antweakbar to display current values of the emitter

	TwBar* UI = TwNewBar("Burst Emitter values");
	TwAddVarRO(UI, "Maximum particles:", TW_TYPE_INT32, &numParticles, "");
	TwAddVarRO(UI, "Particles per burst", TW_TYPE_INT32, &numParticlesPerBurst, "");
	TwAddVarRO(UI, "Burst rate:", TW_TYPE_FLOAT, &burstRate, "");
	TwAddVarRO(UI, "Lifetime:", TW_TYPE_FLOAT, &life, "");
	TwAddVarRO(UI, "Speed:", TW_TYPE_FLOAT, &speed, "");
	TwAddVarRO(UI, "Spread:", TW_TYPE_FLOAT, &spread, "");

}

void BurstEmitter::Tick(GameData* _GD)
{
	//Calculates the spawnTimer based on the delta time
	spawnTimer += _GD->m_dt;

	while (spawnTimer > 1.f / rate)
	{
		//Iterates through a for loop depending on the amount of numParticlesBurst which was defined by the user
		for (int i = 0; i < numParticlesPerBurst; i++)
		{
			bool particleSpawned = false;

			//Loops through the particle list which is populated based on numParticles
			for (Particle* particle : myParticles)
			{
				if (!particle->isAlive())
				{
					/*srand(time(NULL));*/
					//Randomly generates an offset to be applied to the particle direction based on the spread defined by the user
					float randomXOffset = (rand() % (int)spread) - spread / 2.f;
					//float randomYOffset = 0; // rand() % 10;
					Vector2 particlePos = m_pos;
					//Sets the direction of travel of the particle to downwards
					Vector2 particleDir = Vector2(0, 1);
					//Sets the direction of travel for the particle
					particlePos = Vector2::Transform(particlePos, m_worldMat);
					//particleDir = Vector2::Transform(particleDir, m_worldMat) - m_pos;

					//Sets the particle direction to face downwards with the random offset applied
					particleDir = Vector2::Transform(particleDir, Matrix::CreateRotationZ(randomXOffset * 3.142f / 180.0f));
					particlePos.Normalize();
					particleDir.Normalize();
					//Spawns in the current particle in the list based on the values calculated above
					particle->Spawn(life, m_pos, particleDir);
					particleSpawned = true;
					
					break;
				}
			}			
		}

		//spawnTimer is calculated based on the burstRate defined by the user
		spawnTimer -= 1.f / burstRate;
	}
	Emitter::Tick(_GD);
}