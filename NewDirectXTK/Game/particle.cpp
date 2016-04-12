#include "particle.h"

Particle::Particle(string _fileName, float _speed, ID3D11Device* _GD) : ImageGO2D(_fileName, _GD)
{
	m_alive = false;
	m_lifeLeft = 0.0f;
	speed = _speed;
}

Particle::~Particle()
{

}

void Particle::tick(GameData* _GD)
{
	//If the particle is alive continue to tick
	if (m_alive)
	{
		//Calculates lifeleft based on the time currently taken
		m_lifeLeft -= _GD->m_dt;
		if (m_lifeLeft < 0.0f)
		{
			m_alive = false;
			return;
		}

		//Calculates velocity based on speed
		m_pos += speed * _GD->m_dt * m_dir;

		ImageGO2D::Tick(_GD);

	}

}

void Particle::draw(DrawData2D* _DD)
{
	//Draw the particle if alive
	if (m_alive)
	{
		ImageGO2D::Draw(_DD);
	}
}

void Particle::Spawn(float _life, Vector2 _pos, Vector2 _dir)
{
	m_alive = true;
	m_lifeLeft = _life;
	m_pos = _pos;
	m_dir = _dir;
}