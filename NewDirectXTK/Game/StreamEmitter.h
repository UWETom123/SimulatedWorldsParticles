#pragma once

#include "Emitter.h"

class StreamEmitter : public Emitter
{
public:

	StreamEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, string _particleName);

	

	virtual void Tick(GameData* _GD);

	

protected:

	int numParticles;
	float rate;
	float life;
	float speed;
	float spawnTimer;


};