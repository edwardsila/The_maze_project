# The Maze Project

## Introduction
Welcome to The Maze Project! This is a 3D maze game inspired by my love for gaming and the challenge of navigating intricate labyrinths. This project is a testament to my skills in game development, featuring advanced raycasting techniques to render a dynamic and engaging maze experience.

- **Deployed Site:** [The Maze Project Live](https://www.youtube.com/watch?v=sQRoT_skfa8&ab_channel=EdwardSila).
- **Project Blog Article:** [Read the Blog](https://www.linkedin.com/pulse/imagine-trying-find-your-way-through-lines-code-created-edward-sila-qloff).
- **Author's LinkedIn:** [My LinkedIn Profile](https://www.linkedin.com/in/edward-sila-a8a262242/).


## Get Started

To experience The Maze Project:

### setting up SDL2
Before installing the Maze Project, you need to set up SDL2. Follow these steps:

1. **Windows:**
   - Download the SDL2 development libraries from [libsdl.org](https://www.libsdl.org/download-2.0.php).
   - Extract the downloaded archive and copy the contents to a convenient location.
   - Add the SDL2 include directory to your compiler's include path.
   - Add the SDL2 library directory to your linker's library path.
   - Link your project with `SDL2.lib` and `SDL2main.lib`.

2. **macOS:**
   - Install SDL2 using Homebrew:
     ```bash
     brew install sdl2
     ```

3. **Linux (Ubuntu/Debian):**
   - Install SDL2 using apt:
     ```bash
     sudo apt-get install libsdl2-dev
     ```

### Running The Maze Project
1. Now, you can install and run The Maze Project:
    ```bash
    git clone https://github.com/yourusername/the-maze-project.git
    ```
2. Navigate to the project directory:
    ```bash
    cd the-maze-project
    ```

## Technical Challenges

The Maze Project posed several technical challenges, particularly in rendering the maze in a visually appealing way while ensuring smooth navigation. Here are some key challenges I faced:

- **Raycasting Algorithm**: Implementing a raycasting algorithm to render the 3D environment efficiently was one of the core technical challenges. I opted for a modified version of the raycasting technique to achieve the desired visual effect.
  
- **Collision Detection**: Developing an accurate collision detection system to prevent the player from walking through walls while ensuring seamless movement within the maze.

- **Optimization**: Optimizing the rendering pipeline and game logic to maintain a consistent frame rate and smooth gameplay experience, especially on lower-end devices.

## Features

- **Realistic 3D Rendering**: Utilizes raycasting techniques for rendering a 3D maze environment in the browser.
  
- **Responsive Controls**: Navigate through the maze using arrow keys or WASD controls, providing an intuitive and immersive experience.
  
- **Randomly Generated Mazes**: Enjoy endless replayability with randomly generated mazes, offering a new challenge each time you play.

## Technical Details

### Raycasting Algorithm

The raycasting algorithm used in The Maze Project works by casting rays from the player's viewpoint to create the illusion of a 3D environment. Here's a brief overview:

- **Ray Casting**: Each vertical strip on the screen corresponds to a single ray cast from the player's viewpoint.
  
- **Wall Detection**: The algorithm detects intersections between rays and maze walls, determining the distance and height of walls to render them correctly.

- **Texture Mapping**: Textures are applied to the walls based on the ray's intersection point, giving the illusion of depth and detail.

## Future Improvements

While The Maze Project has come a long way, there's always room for improvement:

- **Enhanced Graphics**: Implement shaders and lighting effects to enhance the visual quality of the maze.
  
- **Multiplayer Support**: Introduce multiplayer functionality to race against friends or collaborate in solving complex mazes.

- **Level Editor**: Create a level editor tool to allow players to design and share their own maze creations.


## Usage
Upon launching the game, use the arrow keys or WASD to navigate through the maze. Your objective is to find the exit. Enjoy the thrill of exploration and challenge yourself to complete the maze in the shortest time possible.

## Contributing
Contributions are welcome! If you have ideas for improvements or new features, please open an issue or submit a pull request. Let's make this project even better together.

## Related Projects
- [Monty](https://github.com/edwardsila/monty.git)
- [simple shell](https://github.com/edwardsila/simple_shell.git)

## The maze
! [Maze Project](https://i.imgur.com/deyqDpL.png)

## Licensing
This project is licensed under the MIT License. See the LICENSE file for more details.
