#include "joystickhandler.h"

JoystickHandler::JoystickHandler()
{

}

int JoystickHandler::function_of_handling()
{
    // Инициализация SDL для использования джойстика
    if (SDL_Init(SDL_INIT_JOYSTICK) < 0)
    {
        qDebug() << "Couldn't initialize SDL: " << SDL_GetError();
        exit(1);
    }

    // Создание окна SDL
    SDL_Window *win = SDL_CreateWindow("function_of_handling",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
    if(win==NULL)
    {
        qDebug() << "Couldn't Create window: " << SDL_GetError();
    }

    // Вывод числа и названий всех подключенных джойстиков
    qDebug() << "Joysticks were found: " << SDL_NumJoysticks();
    qDebug() << "The names of the joysticks are:";
    for(int i=0; i < SDL_NumJoysticks(); i++)
    {
        qDebug() << SDL_JoystickNameForIndex(i);
    }

    // Включаем прием событий от всех подключенных джойстиков
    SDL_JoystickEventState(SDL_ENABLE);

    // Переменная для первого джойстика
    SDL_Joystick *joystick;
    SDL_Event event;

    // Открываем чтение с первого джойстка
    joystick = SDL_JoystickOpen(0);

    // Получение и вывод характеристик первого джойстка
    int number_of_axes = SDL_JoystickNumAxes(joystick);
    int number_of_buttons = SDL_JoystickNumButtons(joystick);
    int number_of_balls = SDL_JoystickNumBalls(joystick);
    int number_of_hats = SDL_JoystickNumHats(joystick);
    qDebug() << "Number of axes: " << number_of_axes;
    qDebug() << "Number of buttons: " << number_of_buttons;
    qDebug() << "Number of balls: " << number_of_balls;
    qDebug() << "Number of hats: " << number_of_hats;

    // Инициализация переменных джойстика
    double gammaAxis = 0;
    double thetaAxis = 0;
    double yawAxis = 0;
    double thrustAxis = 0;

    bool quit = false;
    /* Start main game loop here */
    qDebug() << "Start loop";
    while(!quit)
    {
        SDL_Delay(10);
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_JOYAXISMOTION: /* Handle Joystick Motion */
                {
                    if(event.jaxis.axis == 0)
                    {
                        gammaAxis = event.jaxis.value; // считывание значения
                        gammaAxis = round((gammaAxis/32768)*100)/100; // диапазон [-1.00; 1.00]
                    }
                    if(event.jaxis.axis == 1)
                    {
                        thetaAxis = event.jaxis.value; // считывание значения
                        thetaAxis = round((thetaAxis/32768)*100)/100; // диапазон [-1.00; 1.00]
                    }
                    if(event.jaxis.axis == 2)
                    {
                        thrustAxis = event.jaxis.value; // считывание значения
                        thrustAxis = round(((32768-thrustAxis)/65536)*100)/100; // диапазон [0.00; 1.00]
                    }
                    if(event.jaxis.axis == 5)
                    {
                        yawAxis = event.jaxis.value; // считывание значения
                        yawAxis = round((yawAxis/32768)*100)/100; // диапазон [-1.00; 1.00]
                    }
                    qDebug() << gammaAxis << thetaAxis << yawAxis <<thrustAxis;
                }
                break;

                case SDL_KEYDOWN:
                {
                /* handle keyboard stuff here */
                qDebug() << "SDL_KEYDOWN";
                quit = true;
                }
                break;

                case SDL_MOUSEBUTTONDOWN:
                {
                /* handle mouse button stuff here */
                qDebug() << "SDL_MOUSEBUTTONDOWN";
                quit = true;
                }
                break;

                case SDL_QUIT:
                {
                /* Set whatever flags are necessary to */
                /* end the main game loop here */
                qDebug() << "SDL_QUIT";
                quit = true;
                }
                break;

                default:
                break;
            }
        }
    }
    /* End loop here */
    qDebug() << "End loop";

    // Деинициализация SDL
    SDL_Quit();
    return 0;
}



