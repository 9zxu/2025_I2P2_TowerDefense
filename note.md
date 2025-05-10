# ?

> [std::placeholders::_1](https://en.cppreference.com/w/cpp/utility/functional/placeholders)
> [std::bind](https://en.cppreference.com/w/cpp/utility/functional/bind)
## game engine
### keyboard event
> [keyboard routines](https://www.allegro.cc/manual/5/keyboard.html)
```c++
void GameEngine::startEventLoop() {
    // wait for event...
        // detect event...
        case ALLEGRO_EVENT_KEY_DOWN:
            // Event for keyboard key down.
            LOG(VERBOSE) << "Key with keycode " << event.keyboard.keycode << " down";
            activeScene->OnKeyDown(event.keyboard.keycode);
            break;
        //redraw the scene...
            update(timeElapsed.count());
}
```
```
ALLEGRO_EVENT_KEY_DOWN

A keyboard key was pressed.

keyboard.keycode (int)

    The code corresponding to the physical key which was pressed. See the "Key codes" section for the list of ALLEGRO_KEY_* constants.
```
`ALLEGRO_KEYMOD_SHIFT` will not be sent as a `ALLEGRO_EVENT_KEY_DOWN` event, it will return an `unsigned int` from `event.keyboard.modifiers`

## enemy
### enemy wave
according to the following function,
the three numbers specified in each line in `enemy1.txt`, are
`enemy type`, `wait time`, `repeat times` respectively.


```c++
class PlayScene final : public Engine::IScene {
public:
    std::list<std::pair<int, float>> enemyWaveData;
}
```
```c++
void PlayScene::ReadEnemyWave() {
    std::string filename = std::string("Resource/enemy") + std::to_string(MapId) + ".txt";
    // Read enemy file.
    float type, wait, repeat;
    enemyWaveData.clear();
    std::ifstream fin(filename);
    while (fin >> type && fin >> wait && fin >> repeat) {
        for (int i = 0; i < repeat; i++)
            enemyWaveData.emplace_back(type, wait);
    }
    fin.close();
}
```
`enemy type`
```c++
void PlayScene::Update(float deltaTime) {
    // ...
        auto current = enemyWaveData.front();
        if (ticks < current.second)
            continue;
        ticks -= current.second; // deduct wait time
        enemyWaveData.pop_front();
        const Engine::Point SpawnCoordinate = Engine::Point(SpawnGridPoint.x * BlockSize + BlockSize / 2, SpawnGridPoint.y * BlockSize + BlockSize / 2);
        Enemy *enemy;
        switch (current.first) {
            case 1:
                EnemyGroup->AddNewObject(enemy = new SoldierEnemy(SpawnCoordinate.x, SpawnCoordinate.y));
                break;
            // TODO HACKATHON-3 (2/3): Add your new enemy here.
            case 2:
                EnemyGroup->AddNewObject(enemy = new PlaneEnemy(SpawnCoordinate.x, SpawnCoordinate.y));
                break;
            case 3:
                EnemyGroup->AddNewObject(enemy = new TankEnemy(SpawnCoordinate.x, SpawnCoordinate.y));
                break;
            default:
                continue;
        }
    // ...
}
```