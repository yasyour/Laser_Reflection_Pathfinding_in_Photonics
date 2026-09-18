#pragma once

// Marks all grid cells along a line using Bresenham's line algorithm
bool markLine(int** arr, int i, int j, int newX, int newY,
    int xt, int yt, int width, int length) {
    int dx = abs(newX - i);
    int dy = abs(newY - j);
    int sx = (i < newX) ? 1 : -1;
    int sy = (j < newY) ? 1 : -1;
    int err = dx - dy;

    int x = i;
    int y = j;

    while (true) {
        // Mark current cell if within bounds
        if (x >= 0 && x < width && y >= 0 && y < length) {
            arr[y][x] = 1;

            // Check if we hit the target
            if (x == xt && y == yt) {
                return true;  // Stop immediately when target is hit
            }
        }

        // Check if we reached the end point
        if (x == newX && y == newY) break;

        // Bresenham's algorithm step
        int e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x += sx;
        }
        if (e2 < dx) {
            err += dx;
            y += sy;
        }
    }

    return false;
}