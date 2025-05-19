//
// Created by Grace on 2025/5/19.
//

#include "MissileBullet.hpp"

#include <allegro5/base.h>
#include <random>
#include <string>

#include "Enemy/Enemy.hpp"
#include "Engine/Collider.hpp"
#include "Engine/Group.hpp"
#include "Engine/Point.hpp"
#include "Scene/PlayScene.hpp"
#include "UI/Animation/DirtyEffect.hpp"

class Turret;

MissileBullet::MissileBullet(Engine::Point position, Engine::Point forwardDirection, float rotation, Turret *parent) : Bullet("play/bullet-3.png",400,10,position, forwardDirection,rotation - ALLEGRO_PI / 2, parent) {
    float trackingStrength = 0.1f;
    Engine::Point toTarget = (forwardDirection - position).Normalize();
    Velocity = Velocity.Lerp(toTarget * speed, trackingStrength);
}
void MissileBullet::OnExplode(Enemy *enemy) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2, 5);
    getPlayScene()->GroundEffectGroup->AddNewObject(new DirtyEffect("play/dirty-3.png", dist(rng), enemy->Position.x, enemy->Position.y));
}
