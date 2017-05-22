#include "PID.h"

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  step = 0;
  total_err = 0.0;
}

void PID::UpdateError(double cte) {
  if (step > 0) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    total_err += cte*cte;    
  }
  step += 1;
}

double PID::TotalError() {
  if (step == 500) {
    return total_err / step;
  } else {
    return -1;
  }
}

double PID::SteerValue() {
  return -Kp * p_error - Kd * d_error - Ki * i_error;
}

void PID::Restart(uWS::WebSocket<uWS::SERVER> ws) {
  std::string reset_msg = "42[\"reset\",{}]";
  ws.send(reset_msg.data(), reset_msg.length(), uWS::OpCode::TEXT);
}