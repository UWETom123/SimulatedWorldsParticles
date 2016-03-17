#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "ImageGO2D.h"
#include "GameData.h"

class Particle : public ImageGO2D
{

public:
	Particle(string _fileName, float _speed, ID3D11Device* _GD);
	~Particle();

	void Spawn(float _life, Vector2 _pos, Vector2 _dir);

	virtual void tick(GameData* _GD);
	virtual void draw(DrawData2D* _DD);

	bool isAlive(){ return m_alive; }

	float speed;

private:

	bool m_alive;
	float m_lifeLeft;
	Vector2 m_dir;

};

#endif