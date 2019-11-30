#include "CollideGameObject.h"

void CollideGameObject::SetCollisionData()
{
	col.colRadius = m_scale;
	col.pos = m_position;
	col.offset = m_posOffset;
}

void CollideGameObject::UpdateCollisionPosition()
{
	col.pos = m_position;
}

void CollideGameObject::DrawDebug(Color & color)
{
	Collision::DrawCollision(col, color);
}

void CollideGameObject::Update(double elapsedTime)
{
	GameObject::Update();
	UpdateCollisionPosition();
}

bool CollideGameObject::CheckCollision(CollideGameObject * other)
{
	bool collided = Collision::CheckCollision(&col, &other->col);
	if (collided == true)
	{
		return true;
	}

	return false;
}

void CollideGameObject::UpdateFromNetwork(double elapsedTime)
{
}