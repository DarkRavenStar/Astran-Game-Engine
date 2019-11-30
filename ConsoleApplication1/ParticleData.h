#pragma once
#include "AllHeader.h"
#include "Sprite.h"
#include "Transformation.h"
#include "Vector3.h"
#include "Color.h"
#include "Rendering.h"
#include "bitmap.h"
#include "ParticleObject.h"
#include "Affector.h"
#include "EmitterShape.h"

class WindowSize
{
public:
	int windowWidth;
	int windowHeight;
};

class EmissionData
{
public:
	float emissionRate = 1.0f;
	float emmisionLimit = 1.0f;
	float emisionCount = 0.0f;
};

class ParticleData
{
public:
	int particleNum = 20;
	float lifetime = 60.0f;

	EmissionData emissionData;
	Sprite* m_sprite;
	enumBlend m_blendMode;
	DrawShape m_drawShape;
};

enum class MotionType
{
	NONE,
	SPIRAL,
	RANDOM,
};

class SpiralData
{
public:
	int numOfArms = 4;
	float angleBetweenArms = 45.0f;
	bool autoAngleBetweenArms = true;
	float stepSpeed;
};

class ParticleSystemData
{
public:
	bool DrawReverse = false;;
	MotionType motionType = MotionType::SPIRAL;
	SpiralData spiralData;
	EmitterShape* emitterShape = NULL;
	EmitterShapeType emitterShapeType;

	SquareEmitter m_squareEmitter;
	CircleEmitter m_circleEmitter;
	PointEmitter m_pointEmiter;
	RingEmitter m_ringEmitter;

	ColorAffector* newColor;
	ScaleAffector* newScale;
	SpeedAffector* newSpeed;
	GravityAffector* newGravity;
	RotateAffector* newRotation;
};