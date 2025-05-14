//
// Created by Grace on 2025/5/10.
//

#include "ScoreBoardScene.hpp"

#include <iostream>
#include <__ostream/basic_ostream.h>
#include <fstream>

#include "StageSelectScene.hpp"
#include "Engine/GameEngine.hpp"
#include "UI/Component/ImageButton.hpp"
#include "UI/Component/Label.hpp"

const int ScoreBoardScene::recordPerPage = 5;
int ScoreBoardScene::currentPage = 0;

void ScoreBoardScene::Initialize() {
    nameScorePair.clear();
    ReadRecord();
    // AddNewObject(RecordGroup = new Group());

    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    Engine::ImageButton *btn;

    AddNewObject(new Engine::Label("SCOREBOARD", "pirulen.ttf", 100, halfW, halfH / 4 + 50, 0, 255, 0, 255, 0.5, 0.5));

    // prev page btn
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW * 3 / 2 - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreBoardScene::NextOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Next Page", "pirulen.ttf", 48, halfW * 3 / 2 , halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
    // next page btn
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW / 2 - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreBoardScene::PrevOnClick, this, 2));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Prev Page", "pirulen.ttf", 48, halfW / 2, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
    // back btn
    btn = new Engine::ImageButton("stage-select/dirt.png", "stage-select/floor.png", halfW - 200, halfH * 3 / 2 - 50, 400, 100);
    btn->SetOnClickCallback(std::bind(&ScoreBoardScene::BackOnClick, this, 1));
    AddNewControlObject(btn);
    AddNewObject(new Engine::Label("Back", "pirulen.ttf", 48, halfW, halfH * 3 / 2, 0, 0, 0, 255, 0.5, 0.5));
}

void ScoreBoardScene::Draw() const {
    IScene::Draw();
    // record
    int w = Engine::GameEngine::GetInstance().GetScreenSize().x;
    int h = Engine::GameEngine::GetInstance().GetScreenSize().y;
    int halfW = w / 2;
    int halfH = h / 2;

    float startY = halfH / 2 + 50;    // starting y position
    float offsetY = 60;               // vertical spacing between labels
    size_t start = currentPage * recordPerPage;
    size_t end = std::min(start + recordPerPage, nameScorePair.size());
    for (size_t i=start; i<end; i++) {
        std::string displayText = nameScorePair[i].first + " " + std::to_string(nameScorePair[i].second);
        float x = halfW;
        float y = startY + (i-start) * offsetY;
        Engine::Label label(displayText, "pirulen.ttf", 48, x, y, 0, 255, 0, 255, 0.5, 0.5);
        label.Draw();
    }
}

void ScoreBoardScene::Terminate() {
    IScene::Terminate();
}

void ScoreBoardScene::BackOnClick(int stage) {
    Engine::GameEngine::GetInstance().ChangeScene("start");
}

void ScoreBoardScene::NextOnClick(int stage) {
    if (currentPage < nameScorePair.size() / recordPerPage) {
        currentPage++;
    }
}
void ScoreBoardScene::PrevOnClick(int stage) {
    if (currentPage > 0) {
        currentPage--;
    }
}
void ScoreBoardScene::ReadRecord() {
    std::string filename = "Resource/scoreboard.txt";
    std::ifstream fin(filename);
    if (!fin) {
        throw std::runtime_error("File could not be opened");
    }
    std::string name;
    int score;
    while (fin >> name >> score) {
        nameScorePair.emplace_back(name,score);
    }
    fin.close();
}
