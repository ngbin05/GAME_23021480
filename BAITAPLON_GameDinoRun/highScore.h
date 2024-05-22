#ifndef _HSCR_H
#define _HSCR_H

int readHighScore(const char* filePath) {
    std::ifstream file(filePath);
    int highScore = 0;
    if (file.is_open()) {
        file >> highScore;
        file.close();
    }
    return highScore;
}


void saveHighScore(const char* filePath, int highScore) {
    std::ofstream file(filePath);
    if (file.is_open()) {
        file << highScore;
        file.close();
    }
}
#endif // _HSCR_H
