#pragma once
#include "AllHeader.h"
#include "Sprite.h"
#include "Transformation.h"
#include "Vector3.h"
#include "Color.h"
#include "Rendering.h"
#include "Collision.h"

class GameObject
{
protected:
	Sprite* m_sprites = NULL;

	Vector3 m_position = Vector3();
	Vector3 m_velocity = Vector3();
	Vector3 m_acceleration = Vector3();

	MatrixOffset m_posOffset = MatrixOffset();
	float m_rotation = 0.0f;
	Scale m_scale;
	Color m_color;
	enumBlend m_blendMode;
	DrawShape m_shape;

public:
	GameObject();
	GameObject(Sprite* sprite);

	void SetPos(Vector3 pos);
	Vector3& GetPos();

	void SetVel(Vector3 vel);
	Vector3& GetVel();

	void SetAccel(Vector3 accel);
	Vector3& GetAccel();

	void SetPosOffset(MatrixOffset offset);
	MatrixOffset& GetPosOffset();

	void SetRotation(float rotate);
	float& GetRotation();

	void SetScale(float scaleX, float scaleY);
	Scale& GetScale();
	
	void SetSprite(Sprite* sprite);
	Sprite* GetSprite();
	
	void SetColor(Color& color);
	const Color& GetColor();
	
	void SetBlendMode(enumBlend blendMode);
	const enumBlend& GetBlendMode();
	
	void SetShape(DrawShape shape);
	const DrawShape& GetShape();
	
	virtual void Draw();
	virtual void Update();
	virtual void Update(double elapsedTime);
	virtual void Collided();
};