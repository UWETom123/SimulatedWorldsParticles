#include "Emitter.h"
#include <time.h>

class SprayEmitter :public Emitter
{
public:

	SprayEmitter(string _fileName, ID3D11Device* _GD, int _numParticles, float _rate, float _life, float _speed, float _spread, string _particleName);


	virtual void Tick(GameData* _GD);

protected:

	float spread;
	float spawnTimer;

};

