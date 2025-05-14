//
// Created by Grace on 2025/5/10.
//

#ifndef SCOREBOARDSCENE_HPP
#define SCOREBOARDSCENE_HPP
#include"Engine/IScene.hpp"

class ScoreBoardScene final : public Engine::IScene {
public:
    std::vector<std::pair<std::string, int>> nameScorePair;
    // Group *RecordGroup;

    static const int recordPerPage;
    static int currentPage;

    explicit ScoreBoardScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick(int stage);
    void PrevOnClick(int stage);
    void NextOnClick(int stage);
    void ReadRecord();
    void Draw() const override;
};

#endif //SCOREBOARDSCENE_HPP
