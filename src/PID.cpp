#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_in, double Ki_in, double Kd_in) {
  p_error = 0;
  i_error = 0;
  d_error = 0;
  
  Kp = Kp_in;
  Ki = Ki_in;
  Kd = Kd_in;

  prev_cte = 0;
  sum_cte = 0;

  dp[0] = 0.5; 
  dp[1] = 0.05;
  dp[2] = 1;
  increased = false;
  
  i = 0;
  k = 0;
  
  twiddle_flag = false;
  tolerance = 0.01;
  
  summed = 0;
  
  return;
  
};

void PID::UpdateError(double cte) {
  prev_cte = cte;
  sum_cte += cte;
  
  if (summed >= 50) {
    sum_cte -= sum_cte/49;
  };
  
  summed += 1;
  //best_error = prev_cte * prev_cte;
  return;
};


double PID::TotalError() {
  return 0;
};

void PID::Twiddle(double cte) {
  double error = cte * cte;
  //return;
  
  if (error < best_error) {
    best_error = error;
    
  }
  
  /*
  //if (k<30) {
    if (error <= best_error) {
      dp[0] = dp[0] * 1.2;
      Kp = Kp + dp[0];
      best_error = error;
      increased = true;
      k = k + 1;
      return;
    }
    
    else {
      if (increased) {
        Kp = Kp - 2*dp[0];
        increased = false;
        k = k + 1;
        return;
      }
      else {
        dp[0] = dp[0] * 0.8;
        Kp = Kp + dp[0];
        increased = true;
        return;
      }
      
    }; 
  //}
  
  //if ((k >= 60) && (k < 90)) {
    if (error <= best_error) {
      dp[1] = dp[1] * 1.2;
      Ki = Ki + dp[1];
      best_error = error;
      increased = true;
      k = k + 1;
      return;
    }
    
    else {
      
      if (increased) {
        Ki = Ki - 2*dp[1];
        increased = false;
        k = k + 1;
        return;
      }
      else {
        dp[1] = dp[1] * 0.8;
        Ki = Ki + dp[1];
        increased = true;
        return;
      }
      
    };
  //}
  
 // if ((k >= 30) && (k < 60)) {
    if (error <= best_error) {
      dp[2] = dp[2] * 1.2;
      Kd = Kd + dp[2];
      best_error = error;
      increased = true;
      k = k + 1;
      return;
    }
    
    else {
      
      if (increased) {
        Kd = Kd - 2*dp[2];
        increased = false;
        k = k + 1;
        return;
      }
      else {
        dp[2] = dp[2] * 0.8;
        Kd = Kd + dp[2];
        increased = true;
        return;
      }
      
    };
 // }
/*  
  else {
    
    twiddle_flag = false;  
  }
*/
};