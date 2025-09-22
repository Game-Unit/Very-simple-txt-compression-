#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "CompretionKey.h"

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <Vector>
#include <cstdlib>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Text File Compression and Decompression");

    std::string textFileContent;
    FilePathList droppedFiles;

    CompretionKey ck;

    const char* userProfile = std::getenv("USERPROFILE");
    std::string outPathCo;
    if (userProfile) outPathCo = std::string(userProfile) + "\\Downloads\\compressed.txt";
    else outPathCo = "compressed.txt";
    std::string outPathDe;
    if (userProfile) outPathDe = std::string(userProfile) + "\\Downloads\\decompressed.txt";
    else outPathDe = "decompressed.txt";

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        if (IsFileDropped())
        {
            droppedFiles = LoadDroppedFiles();
        }

        BeginDrawing();

        ClearBackground(WHITE);

        DrawText("Drag and drop a .txt file to compress or decompress it.", 10, 10, 10, DARKGRAY);
        DrawText("outputed file will be in downloads", 10, 20, 10, DARKGRAY);

        if (GuiButton({600, 380, 200, 40}, "compress"))
        {
            if (droppedFiles.count == 1)
            {
                textFileContent.clear();
                std::ifstream file(droppedFiles.paths[0]);

                std::string line;
                while (std::getline(file, line))
                {
                    textFileContent += line + "\n";
                }
                file.close();
                // UnloadDroppedFiles(droppedFiles);

                std::map<char, std::string> compretionData = ck.GetCompretionData();
                std::string compressedText;

                std::list<int> chracterCount;
                char lastLetter = ' ';

                for (char ch : textFileContent)
                {
                    if (compretionData.find(ch) != compretionData.end())
                    {
                        if (ch == lastLetter)
                        {
                            chracterCount.back()++;
                        }
                        else
                        {
                            chracterCount.push_back(1);
                            std::cout << compretionData[ch] << " ";
                            compressedText += compretionData[ch] + " ";
                            lastLetter = ch;
                        }
                    }
                    else
                    {
                        compressedText += ch; // If character not found, keep it as is
                    }
                }

                std::ofstream outFile(outPathCo);
                outFile << compressedText;
                outFile << "\n";
                for (int count : chracterCount)
                {
                    outFile << count << " ";
                }
                outFile.close();
                UnloadDroppedFiles(droppedFiles);
            }
        }
        if (GuiButton({600, 410, 200, 40}, "decompress"))
        {

            if (droppedFiles.count == 1)
            {
                std::map<std::string, char> decompresionData = ck.GetDecompretionData();
                std::ifstream file(droppedFiles.paths[0]);

                std::string decompresedText = "";

                if (file.is_open())
                {
                    std::string compressedText;
                    std::string compressedCounts;

                    std::getline(file, compressedText);

                    std::getline(file, compressedCounts);
                    
                    std::vector<int> counts;
                    std::string countStr = "";
                    
                    for (char ch : compressedCounts)
                    {
                        if (ch != ' ')
                        {
                            countStr += ch;
                        }
                        else
                        {
                            counts.push_back(std::stoi(countStr));
                            //std::cout << std::stoi(countStr) << " ";
                            countStr = "";
                        }
                    }

                    for (int i : counts)
                    {
                        std::cout << i << " ";
                    }

                    std::cout << "\n";
                    
                    std::string sequence = "";
                    int countIndex = 0;
                    for (char ch : compressedText)
                    {
                        if (ch != ' ')
                        {
                            sequence += ch;
                        }
                        else
                        {
                            //std::cout << sequence << " ";
                            // if (decompresionData.find(sequence) != decompresionData.end())
                            // {                    

                                //std::cout << counts[countIndex] << " ";

                                for (int i = 0; i < counts[countIndex]; i++)
                                {
                                    decompresedText += decompresionData[sequence];
                                    std::cout << decompresedText << " - " << counts[countIndex] << "\n";
                                }

                                // decompresedText += decompresionData[sequence];
                            //}
                            sequence = "";
                            countIndex++;
                        }
                    }

                    std::ofstream outFile(outPathDe);
                    outFile << decompresedText;
                    outFile.close();
                    file.close();
                    UnloadDroppedFiles(droppedFiles);
                }
            }
        }

        EndDrawing();
    }
}