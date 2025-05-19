//
// Created by Grace on 2025/5/19.
//

#ifndef DOTBULLET_HPP
#define DOTBULLET_HPP
#include "Bullet.hpp"

class Enemy;
class Bullet;
namespace Engine {
    struct Point;
}   // namespace Engine

class DotBullet : public Bullet {
public:
    explicit DotBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret *parent);
    void OnExplode(Enemy *enemy) override;
};

#endif //DOTBULLET_HPP
