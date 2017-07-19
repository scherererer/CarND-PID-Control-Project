# Reflection
Michael P. Scherer

---

## Describe the effect each of the P, I, D components had in your implementation.
	
_Student describes the effect of the P, I, D component of the PID algorithm in their implementation. Is it what you expected? Visual aids are encouraged, i.e. record of a small video of the car in the simulator and describe what each component is set to._

The P value dictates how hard the controller will attempt to correct for the cross track error.
A higher P means that the car will turn much harder to get back to the middle of the lane. The
D value dampens that effect. Increasing the D resists change in the error from causing the
controller to react. By doing this, one can reduce oscillations which occur naturally with a
purely P controller. The I value allows the controller to overcome an error which a P value
alone is unable to overcome.

## Describe how the final hyperparameters were chosen.

_Student discusses how they chose the final hyperparameters (P, I, D coefficients). This could be have been done through manual tuning, twiddle, SGD, or something else, or a combination!_

I started by setting the P to a low value, and I and D to low values. I increased P until I saw
some oscillations, and then introduced D to dampen them. I played with I a little in order to
deal with the hard bends in the road, however it always ended up overshooting due to integral
windup.

At this point, I changed the throttle control to follow this rule:

throttle = throttleGain / (1.0 + fabs (steeringAngle));

The idea here being that if the steering angle is 0 (straight on), then we are allowed to go
full speed. If we are turning, then the car should slow down. This allowed me to use a much
more aggressive P value without running out of the lanes, and the D was likewise increased to
prevent excessive oscillations.
