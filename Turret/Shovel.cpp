//
// Created by Grace on 2025/5/19.
//

#include "Shovel.hpp"

#include <allegro5/base.h>
#include <cmath>
#include <string>

#include "Engine/Group.hpp"
#include "Engine/Point.hpp"
#include "Scene/PlayScene.hpp"

const int Shovel::Price = 0;
Shovel::Shovel(float x, float y)
    : Turret("play/light-2.png", "play/shovel.png", x, y, 0, Price, 0) {
    // Move center downward, since we the turret head is slightly biased upward.
    Anchor.y += 8.0f / GetBitmapHeight();
    istool = true;
}
void Shovel::CreateBullet() {
}
void Shovel::Update(float deltaTime) {

}