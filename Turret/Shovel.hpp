//
// Created by Grace on 2025/5/19.
//

#ifndef SHOVEL_HPP
#define SHOVEL_HPP
#include "Turret.hpp"


class Shovel : public Turret {
public:
    static const int Price;
    Shovel(float x, float y);
    void CreateBullet() override;
    void Update(float deltaTime)override;
};

#endif //SHOVEL_HPP
