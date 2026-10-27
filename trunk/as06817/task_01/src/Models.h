#pragma once
#include "Model.h"
#include <cmath>

// Model 1.7: y_{t+1} = a*y_t + b1*u_t + b2*u_{t-1} + b3*u_{t-2}
class Model1_7 : public Model {
private:
    double a, b1, b2, b3;
    double y, u1, u2;
public:
    Model1_7(double a, double b1, double b2, double b3) 
        : a(a), b1(b1), b2(b2), b3(b3), y(0), u1(0), u2(0) {}
    double step(double u) override {
        double y_next = a * y + b1 * u + b2 * u1 + b3 * u2;
        u2 = u1;
        u1 = u;
        y = y_next;
        return y;
    }
    void reset() override { y = 0; u1 = 0; u2 = 0; }
};

// Model 2.1: y_{t+1} = a*y_t - b*y_{t-1}^2 + c*u_t + d*sin(u_{t-1})
class Model2_1 : public Model {
private:
    double a, b, c, d;
    double y, y_prev, u_prev;
public:
    Model2_1(double a, double b, double c, double d) 
        : a(a), b(b), c(c), d(d), y(0), y_prev(0), u_prev(0) {}
    double step(double u) override {
        double y_next = a * y - b * (y_prev * y_prev) + c * u + d * std::sin(u_prev);
        y_prev = y;
        y = y_next;
        u_prev = u;
        return y;
    }
    void reset() override { y = 0; y_prev = 0; u_prev = 0; }
};

// Model 3.5: dy/dt = b*sin(u) -> Euler: y_{t+1} = y_t + dt*b*sin(u)
class Model3_5 : public Model {
private:
    double b, dt;
    double y;
public:
    Model3_5(double b, double dt) : b(b), dt(dt), y(0) {}
    double step(double u) override {
        y = y + dt * b * std::sin(u);
        return y;
    }
    void reset() override { y = 0; }
};