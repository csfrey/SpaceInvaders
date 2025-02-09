#include "raylib.h"
#include "menu.h"

int NUM_OPTIONS = 3; // "Start Game", "Difficulty", "Exit"
double lastSwitchTime = 0.0; // Timer to control key repeat rate
const double switchCooldown = 0.2; // 200ms delay between switches

Menu::Menu()
{
    currentOption = 0;
}

void Menu::Update(GameState &gameState)
{
    double currentTime = GetTime(); // Get the current time

    if (IsKeyPressed(KEY_UP))
        currentOption = (currentOption - 1 + NUM_OPTIONS) % NUM_OPTIONS;
    else if (IsKeyPressed(KEY_DOWN))
        currentOption = (currentOption + 1) % NUM_OPTIONS;

    // Continuous difficulty switching
    if (currentOption == 1) // Only change difficulty if "Difficulty" is selected
    {
        if ((IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_LEFT)) && (currentTime - lastSwitchTime > switchCooldown))
        {
            if (IsKeyDown(KEY_RIGHT))
                gameState.difficulty = Difficulty((gameState.difficulty + 1) % DIFFICULTY_SIZE);
            else if (IsKeyDown(KEY_LEFT))
                gameState.difficulty = Difficulty((gameState.difficulty - 1 + DIFFICULTY_SIZE) % DIFFICULTY_SIZE);
            
            lastSwitchTime = currentTime; // Reset the timer
        }
    }

    if (IsKeyPressed(KEY_ENTER))
    {
        switch (currentOption)
        {
        case 0: // Start Game
            gameState.sceneState = GAME;
            break;
        case 2: // Exit
            gameState.sceneState = EXIT;
            break;
        default:
            break;
        }
    }
}

void Menu::Draw(GameState &gameState)
{
    // Get screen width
    int screenWidth = GetScreenWidth();

    // Title
    const char *title = "SPACE INVADERS";
    int titleFontSize = 40;
    int titleWidth = MeasureText(title, titleFontSize);
    DrawText(title, (screenWidth - titleWidth) / 2, 100, titleFontSize, WHITE);

    // Menu Options
    const char *options[] = {"Start Game", "Difficulty", "Exit"};
    int menuFontSize = 30;
    int menuStartY = 200;
    int spacing = 50;

    // Draw "Start Game"
    int startGameWidth = MeasureText(options[0], menuFontSize);
    DrawText(options[0], (screenWidth - startGameWidth) / 2, menuStartY, menuFontSize, currentOption == 0 ? YELLOW : WHITE);

    // Draw "Difficulty" menu option
    int difficultyLabelWidth = MeasureText(options[1], menuFontSize);
    DrawText(options[1], (screenWidth - difficultyLabelWidth) / 2, menuStartY + spacing, menuFontSize, currentOption == 1 ? YELLOW : WHITE);

    // Difficulty Selection (fixed position chevrons)
    const char *difficultyText;
    Color difficultyColor;

    switch (gameState.difficulty)
    {
    case EASY:
        difficultyText = "EASY";
        difficultyColor = GREEN;
        break;
    case MEDIUM:
        difficultyText = "MEDIUM";
        difficultyColor = YELLOW;
        break;
    case HARD:
        difficultyText = "HARD";
        difficultyColor = RED;
        break;
    default:
        difficultyText = "UNKNOWN";
        difficultyColor = WHITE;
        break;
    }

    // **Fixing the Chevrons in Place**
    int maxDifficultyWidth = MeasureText("MEDIUM", menuFontSize); // Longest difficulty word sets fixed width
    int difficultyTextWidth = MeasureText(difficultyText, menuFontSize);
    int chevronSpacing = 20; // Fixed space between chevrons and text

    // **Centering Everything Properly**
    int difficultyBoxWidth = maxDifficultyWidth + (chevronSpacing * 2); // Total width of the difficulty area
    int difficultyBoxX = (screenWidth - difficultyBoxWidth) / 2; // Center difficulty box

    // Positioning elements within the box
    int chevronLeftX = difficultyBoxX;
    int difficultyTextX = difficultyBoxX + chevronSpacing + (maxDifficultyWidth - difficultyTextWidth) / 2;
    int chevronRightX = difficultyBoxX + difficultyBoxWidth - MeasureText(">", menuFontSize);

    // Render the chevrons and text separately (fixed positions)
    DrawText("<", chevronLeftX, menuStartY + spacing * 2, menuFontSize, WHITE);
    DrawText(difficultyText, difficultyTextX, menuStartY + spacing * 2, menuFontSize, difficultyColor);
    DrawText(">", chevronRightX, menuStartY + spacing * 2, menuFontSize, WHITE);

    // Draw "Exit" below the difficulty selection
    int exitWidth = MeasureText(options[2], menuFontSize);
    DrawText(options[2], (screenWidth - exitWidth) / 2, menuStartY + spacing * 3, menuFontSize, currentOption == 2 ? YELLOW : WHITE);
}
