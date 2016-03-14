#ifndef _EMITTER_H_
#define _EMITTER_H_
#include "ImageGO2D.h"
#include "particle.h"
#include <list>

class Emitter :public ImageGO2D
{
public:
	Emitter(string _fileName, ID3D11Device* _GD, int _numParticles, string _particleName);
	virtual ~Emitter();

	virtual void Tick(GameData* _GD);
	virtual void Draw(DrawData2D* _DD);

	list<Particle*> myParticles;

protected:

	GameObject2D* m_parent;
	ID3D11ShaderResourceView* m_pTextureRV;

};

#endif