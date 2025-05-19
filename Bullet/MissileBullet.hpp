//
// Created by Grace on 2025/5/19.
//

#ifndef MISSILEBULLET_HPP
#define MISSILEBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Bullet;

namespace Engine {
    struct Point;
} // namespace Engine

class MissileBullet : public Bullet {
public:
    explicit MissileBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret *parent);

    void OnExplode(Enemy *enemy) override;

};

#endif //MISSILEBULLET_HPP
