#pragma once
#include "GameObject.h"

class CollideGameObject : public GameObject
{
public:
	Collision col;
	Vector3 rotVector = Vector3();

	CollideGameObject(Sprite* sprite) : GameObject(sprite) {}
	CollideGameObject() {}

	virtual void SetCollisionData();
	virtual void UpdateCollisionPosition();
	virtual bool CheckCollision(CollideGameObject* other);
	virtual void DrawDebug(Color& color);
	virtual void Update(double elapsedTime) override;
	virtual void UpdateFromNetwork(double elapsedTime);
};