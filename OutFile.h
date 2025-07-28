#include <cstdlib>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

struct Out {

  Out() {}

private:
  std::vector<int> GenRandomData(int numberOfValues) {
    std::vector<int> numData;
    int minimumNum = 1;
    int maximumNum = 255000;
    int difference = maximumNum - minimumNum;

    for (int i = 0; i < numberOfValues; i++) {
      int randomNum = rand() % difference + minimumNum;
      numData.push_back(randomNum);
    }
    return numData;
  }

  void ConvertNumToString(int amount, const char seperater) {
    std::vector<int> random = GenRandomData(amount);
    for (int i = 0; i < static_cast<int>(random.size()); i++) {
      int num = random[i];
      std::string temp = std::to_string(num) + seperater;
      allData.push_back(temp);
    }
  }

  void GenerateFile() {
    std::ofstream fileOut("random.txt");
    for (std::string data : allData) {
      if (fileOut.is_open()) {
        fileOut << data;
      }
    }
  }

public:
  void Run(int amount, const char seperater)
  {
    ConvertNumToString(amount, seperater);
    GenerateFile();
  }


private:
  std::vector<std::string> allData;
};