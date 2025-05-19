//
// Created by Grace on 2025/5/19.
//

#ifndef DOTTURRET_HPP
#define DOTTURRET_HPP
#include "Turret.hpp"

class DotTurret : public Turret {
public:
    static const int Price;
    DotTurret(float x, float y);
    void CreateBullet() override;
};

#endif //DOTTURRET_HPP
