#pragma once

#include "Emitter.h"

class BurstEmitter : public Emitter
{
public:

	BurstEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, int _numParticlesPerBurst, float _burstRate, float _life, float _speed, float _spread, string _particleName);

	virtual void Tick(GameData* _GD);

protected:

	int numParticlesPerBurst;
	float spawnTimer;
	float spread;
	float burstRate;

};