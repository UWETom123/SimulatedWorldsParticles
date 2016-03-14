//#include "particleManager.h"
//
//ParticleManager::ParticleManager(string _particleName, int _numParticles, ID3D11Device* _GD)
//{
//
//	for (int i = 0; i < _numParticles; i++)
//	{
//		myParticles.push_back(new Particle(_particleName, _GD));
//	}
//
//}
//
//ParticleManager::~ParticleManager()
//{
//
//	for (Particle* particle : myParticles)
//	{
//		delete particle;
//	}
//
//}
//
//void ParticleManager::tick(GameData* data)
//{
//
//	for (Particle* particle : myParticles)
//	{
//		if (!particle->isAlive())
//		{
//
//			Vector2 particlePos = Vector2::Zero;
//			Vector2 particleDir = Vector2::Zero;
//
//			//Sets the direction of travel for the particle
//
//			particlePos = Vector2::Transform(particlePos, m_worldMat);
//			particleDir = Vector2::Transform(particleDir, m_worldMat) - particlePos;
//			particleDir.Normalize();
//			particlePos.Normalize();
//			particle->Spawn(3.0f, particlePos, particleDir);
//			break;
//		}
//
//	}
//
//}
//
//void ParticleManager::Draw(DrawData2D* _DD)
//{
//	for (Particle* particle : myParticles)
//	{
//		if (particle->isAlive())
//		{
//			particle->draw(_DD);
//
//		}
//
//	}
//
//
//}