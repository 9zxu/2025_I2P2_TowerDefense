//
// Created by Grace on 2025/5/10.
//

#ifndef SCOREBOARDSCENE_HPP
#define SCOREBOARDSCENE_HPP

#include<set>
#include<algorithm>
#include"Engine/IScene.hpp"


struct ScoreComparator {
    bool operator()(const std::pair<std::string, int>& a,
                    const std::pair<std::string, int>& b) const {
        if (a.second != b.second)
            return a.second > b.second; // Sort by score descending
        return a.first < b.first;       // Tie-break by name ascending
    }
};

class ScoreBoardScene final : public Engine::IScene {
public:
    // static std::vector<std::pair<std::string, int>> nameScorePair;
    static std::set<std::pair<std::string, int>, ScoreComparator> nameScorePair;

    static const int recordPerPage;
    static int currentPage;

    static void CalculateScore(int lives, int money);
    static void ReadRecord();
    static void WriteRecord();

    explicit ScoreBoardScene() = default;
    void Initialize() override;
    void Terminate() override;
    void BackOnClick(int stage);
    void PrevOnClick(int stage);
    void NextOnClick(int stage);

    void Draw() const override;
};

#endif //SCOREBOARDSCENE_HPP
