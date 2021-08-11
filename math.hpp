
#define RAD2DEG(x) DirectX::XMConvertToDegrees(x)
#define DEG2RAD(x) DirectX::XMConvertToRadians(x)
#define PI 3.14159265358979323846


namespace Math
{
	int TimeToTicks(float);
	void VectorSubtract(const Vector&,const Vector&,Vector&);
	float GetFov(Vector,Vector,Vector);
	void CalcAngle(Vector &,Vector&,Vector&);
	void angleVectors(Vector, Vector&);
	float AngleNormalize(float);
	void ClampAngles(Vector&);
	Vector MakeVector(Vector);
}
