#include "include.hpp"


int Math::TimeToTicks(float deltaTime)
{
	return ((int)0.5f + deltaTime / pGlobalVars->pertick);
}

void Math::VectorSubtract(const Vector& a, const Vector& b, Vector& c)
{
	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
}

Vector Math::MakeVector(Vector viewangle)
{
	auto sy = sin(viewangle.y / 180.f * static_cast<float>(3.141592654f));
	auto cy = cos(viewangle.y / 180.f * static_cast<float>(3.141592654f));

	auto sp = sin(viewangle.x / 180.f * static_cast<float>(3.141592654f));
	auto cp = cos(viewangle.x / 180.f* static_cast<float>(3.141592654f));

	return Vector(cp*cy, cp*sy, -sp);
}

float Math::GetFov(Vector vLocalOrigin, Vector vPosition, Vector vForward)
{
	Vector vLocal;

	Math::VectorSubtract(vPosition, vLocalOrigin, vLocal);

	vLocal.NormalizeInPlace();

	float fValue = vForward.Dot(vLocal);

	if (fValue < -1.0f)
		fValue = -1.0f;

	if (fValue > 1.0f)
		fValue = 1.0f;

	return RAD2DEG(acos(fValue));
}

void Math::ClampAngles(Vector& angle)
{
	if (angle.x > 89.0f) angle.x = 89.0f;
	else if (angle.x < -89.0f) angle.x = -89.0f;

	if (angle.y > 180.0f) angle.y = 180.0f;
	else if (angle.y < -180.0f) angle.y = -180.0f;

	angle.z = 0;
}

void Math::CalcAngle(Vector &vSource, Vector &vDestination, Vector &qAngle)
{
	Vector vDelta = vSource - vDestination;

	float fHyp = (vDelta.x * vDelta.x) + (vDelta.y * vDelta.y);

	float fRoot;

	__asm
	{
		sqrtss xmm0, fHyp
		movss fRoot, xmm0
	}

	qAngle.x = RAD2DEG(atan(vDelta.z / fRoot));
	qAngle.y = RAD2DEG(atan(vDelta.y / vDelta.x));

	if (vDelta.x >= 0.0f)
		qAngle.y += 180.0f;

	qAngle.x = AngleNormalize(qAngle.x);
	qAngle.y = AngleNormalize(qAngle.y);
}

void sinCos(float radians, PFLOAT sine, PFLOAT cosine)
{
	__asm
	{
		fld dword ptr[radians]
		fsincos
		mov edx, dword ptr[cosine]
		mov eax, dword ptr[sine]
		fstp dword ptr[edx]
		fstp dword ptr[eax]
	}
}

void Math::angleVectors(Vector angles, Vector &f)
{
	float sp, sy, sr, cp, cy, cr;

	sinCos(DEG2RAD(angles[0]), &sp, &cp);
	sinCos(DEG2RAD(angles[1]), &sy, &cy);
	sinCos(DEG2RAD(angles[2]), &sr, &cr);

	f[0] = cp * cy;
	f[1] = cp * sy;
	f[2] = -sp;
}

float Math::AngleNormalize(float angle)
{
	while (angle < -180)    angle += 360;
	while (angle > 180)    angle -= 360;

	return angle;
}
