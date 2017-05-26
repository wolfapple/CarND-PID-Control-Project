## PID Controller
PID controller is the most popular type of control technique. The PID controller basically has the form of a feedback controller, calculates an error by measuring an output value of a target to be controlled, and calculates a control value necessary for the control using the error value.

The standard type PID controller is configured to calculate the control value using the following three terms.

### Proportional
P is the proportional control method that changes the control amount in proportion to the error between the target value and the current control value. Obviously, if the error is large, the control amount is increased, but as the error is gradually decreased, the variation amount of the control amount is also decreased. If the proportional gain is too high, the system can become unstable. In contrast, a small gain results in a small output response to a large input error.

* The proportional term serves to reduce the time to reach the target value.

### Integral
The PI control method is used as a way of solving the problem that the deviation of the P control is reduced but the error is not equal to zero. If P control is used, there is always error. PI control is the process of integrating this error with time and reducing the error to the maximum when it is collected above a certain value.

* The integral term acts to eliminate the steady-state error.

### Derivative
The derivative of the process error is calculated by determining the slope of the error over time and multiplying this rate of change by the derivative gain Kd. In other words, when the amount of change in the error value is large, the manipulated variable increases sharply, and when the amount of change decreases, the manipulated amount also decreases. Suddenly, when sudden force is applied in one direction, PID control is added to the control to offset the force in the opposite direction.

* The derivative term brakes the sudden change in output value to reduce overshoot and improve stability.

## Tuning the parameters
I implemented a twiddle algorithm that learned in class for parameter tuning. To enable twiddle just run the following.
```
./pid twiddle
```

It was possible to obtain parameters(0.0568875, 0, 6.7078) that enables a fairly low error and a stable running after a few driving cycles. It was generally satisfactory, but there was a problem that the car moved slightly off the center of the road. I stopped twiddle execution and decided to try a few manual tweaks.

* First, the Kp value was slightly increased(+0.2) to center the car on the road.
* I decided to adjust the Ki value slightly for a more stable running on the straight road. I set a small value(0.0001) close to 0 because a problem occurred even if I increased a little.
* After several tests, the Kd value was increased by 0.1. The stability of the car was improved by damping the oscillation caused by Kp.
* Finally, the parameters I settled on are: (0.2568875, 0.0001, 6.8078)