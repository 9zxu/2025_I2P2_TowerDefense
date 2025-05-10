//
// Created by Grace on 2025/5/10.
//

#ifndef SCOREBOARDSCENE_HPP
#define SCOREBOARDSCENE_HPP
#include"Engine/IScene.hpp"

class ScordBoardScene final : public Engine::IScene {
public:
    explicit ScordBoardScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick(int stage);
    void PrevOnClick(int stage);
    void NextOnClick(int stage);
};

#endif //SCOREBOARDSCENE_HPP
