#ifndef RAMP_CFG_HPP
#define RAMP_CFG_HPP

class RampWidget;
namespace touchgfx {
	struct Point;
}

class RampCfg {
public:
	RampCfg(RampWidget &wiget);
	void setAngle(double ang, const touchgfx::Point & rot_point);

private:
	RampWidget & _Wiget;
};

#endif
