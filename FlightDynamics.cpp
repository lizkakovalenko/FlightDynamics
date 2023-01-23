#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.81; // gravitational acceleration, m/s^2

class Aircraft {
    public:
        double velocity; // velocity, m/s
        double altitude; // altitude, m
        double thrust; // thrust, N
        double drag; // drag, N

        // function to update aircraft's velocity and altitude
        void update(double time) {
            double acceleration = (thrust - drag) / mass;
            velocity += acceleration * time;
            altitude += velocity * time;
        }
};

int main() {
    Aircraft plane;
    plane.velocity = 0;
    plane.altitude = 0;
    plane.thrust = 100000; // 100 kN
    plane.drag = 50000; // 50 kN
    plane.mass = 200000; // 200 metric tons 

    double time = 0;
    double dt = 0.1; // time step, s

    while (plane.altitude >= 0) {
        cout << "Time: " << time << endl;
        cout << "Velocity: " << plane.velocity << " m/s" << endl;
        cout << "Altitude: " << plane.altitude << " m" << endl;

        plane.update(dt);
        time += dt;
    }

    cout << "Aircraft has landed." << endl;

    return 0;
}
