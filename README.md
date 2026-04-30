<div align="center">
<a href="https://github.com/hadi14250">
    <img src="github_gifs/fdf.png" alt="fdf picture" width="150" height="150">
  </a>
  <h3 align="center">FDF</h3>
  A wireframe renderer that turns elevation maps into 3D isometric landscapes.
  <br>
  <br>
</div>

<div align="center">
<a href="https://github.com/hadi14250">
    <img src="github_gifs/fdf.gif" alt="gif"  width="600" height="400">
  </a>


</div>

<br>


# FDF

**FDF** (*fil de fer* — "wire frame" in French) is a graphics project from the 42 curriculum. It reads a `.fdf` map file containing a grid of elevation values and renders it as a 3D wireframe in an isometric projection.

The project is written from scratch in ANSI C using only the [MiniLibX](https://github.com/42Paris/minilibx-linux) graphics library and a custom libft. It focuses on fundamentals: parsing, memory management, linear algebra basics (rotation, projection, scaling), and Bresenham's line algorithm for drawing the connecting segments between points.

<br>

## Features

- 🗺️ Isometric 3D projection of any well-formed `.fdf` elevation map
- 🔍 Zoom in and out on the rendered grid
- 📏 Adjust the height (z-axis amplitude) of the terrain
- 🎨 Color handling based on elevation
- 🖼️ Toggle between flat (2D) and isometric (3D) views
- ⬆️⬇️⬅️➡️ Pan the map around the window

<br>

## Build & Run

```sh
make                       # compile the project
./fdf test_maps/42.fdf     # run with one of the included maps
```

A variety of test maps live in `test_maps/` — try `pyramide.fdf`, `julia.fdf`, `elem-col.fdf`, or `pylone.fdf` to see different terrain shapes.

<br>

## Controls

| Key             | Action                                  |
| --------------- | --------------------------------------- |
| `← ↑ → ↓`       | Move the map around the window         |
| `+` / `-`       | Zoom in / out                           |
| `1`             | Flatten elevation (remove z-axis)       |
| `2`             | Switch to 2D top-down view              |
| `3`             | Switch back to 3D isometric view        |
| `Esc`           | Quit                                    |

<br>

## Project Layout

```
fdf.c                 entry point
parse_map.c           reads the .fdf file into a grid
parse_cords.c         tokenizes coordinate / color values
grids_and_points.c    builds the point matrix
bressen.c             Bresenham line drawing
visuals.c             isometric projection & rendering
movements.c           pan / zoom / height transforms
key_hooks.c           keyboard input handling
color_handle.c        per-point color logic
fdf.h                 shared types and prototypes
libft/                custom standard library
mlx/                  MiniLibX graphics library
test_maps/            sample .fdf maps
```
