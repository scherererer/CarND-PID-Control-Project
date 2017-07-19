#include "PID.h"

#include <algorithm>
using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() :
	p_error_ (0.0),
	i_error_ (0.0),
	d_error_ (0.0),
	last_error_ (0.0),
	Kp_ (1.0),
	Ki_ (0.0),
	Kd_ (0.0)
{
}

PID::~PID()
{
}

void PID::Init(double Kp, double Ki, double Kd)
{
	Kp_ = Kp;
	Ki_ = Ki;
	Kd_ = Kd;
}

void PID::UpdateError(double cte)
{
	p_error_ = Kp_ * cte;

	/// \todo Should bound this, probably to within [-1,1]
	i_error_ += Ki_ * cte;

	/// \todo this has an impulse at startup
	d_error_ = Kd_ * (p_error_ - last_error_);

	last_error_ = cte;
}

double PID::TotalError()
{
	double const pid = p_error_ + i_error_ + d_error_;
	return std::max (std::min (pid, 1.0), -1.0);
}

