# Cyberpunk Christmas Tree (JS Edition)

A festive, browser-based visual project that generates a procedural Christmas tree using JavaScript. The project features a "Cyberpunk" aesthetic with a neon color palette and dynamic lighting effects.

## Features

- **Procedural Generation**: The tree structure (canopy and trunk) is generated dynamically via JavaScript based on a row-count variable.
- **Dynamic Lighting**: Approximately 15% of the tree's "stars" act as neon lights that change color every second.
- **Cyberpunk Aesthetics**: Uses a custom CSS radial gradient background and high-contrast neon colors (Cyan and Magenta) to deviate from traditional holiday themes.
- **Responsive Colors**: The `utils.js` library manages color randomization within specific RGB ranges to maintain visual consistency for the leaves, trunk, and lights.

## Project Structure

- `main.html`: The entry point containing the UI structure, CSS styles, and script references.
- `script/albero.js`: Handles the logic for drawing the tree and trunk using string manipulation and DOM injection.
- `script/Lights.js`: Manages the asynchronous "shuffling" logic and the infinite loop that controls the blinking light animations.
- `script/utils.js`: A helper utility for generating random colors within defined boundaries.

## How to Run

Simply open `main.html` in any modern web browser. No compilation or external dependencies are required.

## Technical Details

The animation is handled through an asynchronous `while(true)` loop in `Lights.js`, utilizing a custom `delay` function based on Promises to prevent blocking the main execution thread. The lighting selection uses a Fisher-Yates shuffle algorithm to ensure a truly random distribution of active lights.
