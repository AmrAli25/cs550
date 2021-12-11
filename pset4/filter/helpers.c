#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float avg = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(avg);
            image[i][j].rgbtGreen = round(avg);
            image[i][j].rgbtRed = round(avg);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float avg_red, avg_green, avg_blue;
    RGBTRIPLE blured_image[height][width];
    int count;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            avg_red = avg_green = avg_blue = count = 0;
            // add zero padding to the image
            for (int r = i - 1; r <= i + 1; r++)
            {
                for (int c = j - 1; c <= j + 1; c++)
                {
                    if ((r >= 0 && r < height) && (c >= 0 && c < width))
                    {
                        // get the number of pixels and add them
                        avg_red += image[r][c].rgbtRed;
                        avg_blue += image[r][c].rgbtBlue;
                        avg_green += image[r][c].rgbtGreen;
                        count++;
                    }
                }
            }
            if (count > 0)
            {
                // get the average
                avg_red = round(avg_red / (float) count);
                avg_blue = round(avg_blue / (float) count);
                avg_green = round(avg_green / (float) count);
                // and store the blured image
                blured_image[i][j].rgbtRed = avg_red;
                blured_image[i][j].rgbtGreen = avg_green;
                blured_image[i][j].rgbtBlue = avg_blue;
            }


        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // copy the blured image
            image[i][j] = blured_image[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // define
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    int red, green, blue, red_x, green_x, blue_x, red_y, green_y, blue_y;
    RGBTRIPLE copy[height][width];


    // make a copy of the image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // loop over all the pexils

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            red_x = blue_x = green_x = red_y = blue_y = green_y = 0;

            //  loop for the Gx and Gy
            for (int r = 0; r < 3; r++)
            {
                for (int c = 0; c < 3; c++)
                {
                    // pixel on the edges

                    if ((i - 1 + r) < 0 || (i - 1 + r) > height - 1 || (j - 1 + c) < 0 || (j - 1 + c) > width - 1)
                    {
                        continue ;
                    }

                    // edge detection in x direction
                    red_x += copy[i - 1 + r][j - 1 + c].rgbtRed * Gx[r][c];
                    blue_x += copy[i - 1 + r][j - 1 + c].rgbtBlue * Gx[r][c];
                    green_x += copy[i - 1 + r][j - 1 + c].rgbtGreen * Gx[r][c];

                    // edge detection in y direction
                    red_y += copy[i - 1 + r][j - 1 + c].rgbtRed * Gy[r][c];
                    blue_y += copy[i - 1 + r][j - 1 + c].rgbtBlue * Gy[r][c];
                    green_y += copy[i - 1 + r][j - 1 + c].rgbtGreen * Gy[r][c];

                }
            }

            // calculate the Gx
            float sr = sqrt((red_x * red_x) + (red_y * red_y));
            float sg = sqrt((green_x * green_x) + (green_y * green_y));
            float sb = sqrt((blue_x * blue_x) + (blue_y * blue_y));

            // rounding it
            red = round(sr);
            green = round(sg);
            blue = round(sb);

            // cap the rgb to 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            // store the data

            image[i][j].rgbtRed = red;
            image[i][j].rgbtBlue = blue;
            image[i][j].rgbtGreen = green;
        }
    }

    return;
}
