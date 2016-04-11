#pragma once

#include "Emitter.h"

class BurstEmitter : public Emitter
{
public:

	BurstEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, string _particleName);


	virtual void Tick(GameData* _GD);

protected:

	float spawnTimer;


};