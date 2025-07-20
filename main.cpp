#include<iostream>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>

float angel=0;
float move1=0.0;
float move2=0.0;
float planeMoveX=0.0;
float planeMoveY=0.0;
float matroMove=0.0;
float speed=0.1;

float bombY = 45.0f;
float bombX = -55.0f;
bool bombDropped = false;
bool exploded = false;
int explosionTimer = 0;
bool damageVisible = true;

float shockwaveRadius = 0;
bool showShockwave = false;
bool explosionVisible = false;

float cloudMoveX = -15.0f;




void drawRoadCrack(float x, float y)
{
    glColor3ub(40, 40, 40);
    glLineWidth(4);
    glBegin(GL_LINE_STRIP);
    glVertex2f(x, y);
    glVertex2f(x + 1, y - 0.5);
    glVertex2f(x + 2, y - 1.5);
    glVertex2f(x + 3, y - 1.2);
    glVertex2f(x + 4, y - 2);
    glEnd();
}
void fire()
{
    GLfloat coordinates[17][2] = {
        {11.041368705901, 11.3181156850938},
        {14.3863903074953, 11.3707873927616},
        {16.624937833768, 12.2295422769481},
        {15.2291376301801, 12.9509386227956},
        {16.6776095910445, 14.0307086299855},
        {14.4653978689979, 13.8200279931434},
        {15.3081451916818, 16.0058976675279},
        {13.5963146924783, 14.8997918065041},
        {13.2802844644715, 16.3745996212025},
        {12.7535673697935, 15.0314710756763},
        {11.4104388246464, 16.5852864518737},
        {11.8054766317731, 14.6627691212999},
        {9.4615856405561, 15.8215469069060},
        {10.3833405247426, 14.1097161914871},
        {8.645174717052, 14.1097161914871},
        {10.1199819864036, 12.9509386227956},
        {8.8031892497486, 12.5559008152871}
    };

    glColor3ub(237, 21, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 17; i++) {
        glVertex2f(coordinates[i][0], coordinates[i][1]);
    }
    glEnd();

    GLfloat yellowCoordinates[13][2] = {
        {13.411963715641, 11.3444515389277},
        {14.3863903074953, 13.0562820381312},
        {13.6489864001461, 12.6875800844566},
        {13.7279939616478, 13.9253652146499},
        {13.0695976158003, 13.372312284138},
        {12.6482239544579, 14.0833803376533},
        {12.621888100624, 13.1879613073007},
        {11.9108200471087, 13.899029360816},
        {11.8844841932748, 13.0826178919651},
        {11.0417368705901, 13.372312284138},
        {11.4631105319324, 12.5032291076193},
        {11.0154010167562, 12.4242215461176},
        {12.3848654161189, 11.3181156850938}
    };

    glColor3ub(254, 182, 16);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 13; i++) {
        glVertex2f(yellowCoordinates[i][0], yellowCoordinates[i][1]);
    }
    glEnd();
}

void tankwheel(float centerX, float centerY)
{
    float radius = 1.0728538803084;
    glColor3ub(90, 90, 90);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(centerX, centerY);
    for (int i = 0; i <= 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        float x = radius * cos(angle) + centerX;
        float y = radius * sin(angle) + centerY;
        glVertex2f(x, y);
    }
    glEnd();
}
void tank()
{
    GLfloat coordinates3[9][2] = {
    {-39.575510266915, -11.3301979636606},
    {-22.3012106779347, -11.3897645303805},
    {-21.5864118772965, -12.1343466143786},
    {-22.569620228174, -13.5639442156511},
    {-24.2660973796989, -14.4574427164528},
    {-37.4311186247769, -14.4276594330292},
    {-39.3670320431721, -13.7724279191745},
    {-40.4987968108492, -12.7002289982172},
    {-40.4690135274893, -11.8067304974195}
    };

    //Wheel part
    glColor3ub(0,0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 9; i++) {
        glVertex2f(coordinates3[i][0], coordinates3[i][1]);
        }
    glEnd();


    GLfloat coordinates4[6][2] = {
    {-40.5586333775691, -11.300146803007},
    {-21.5864118772965, -11.3599812470206},
    {-23.6414584291313, -10.0197334958239},
    {-26.3219539315246, -9.2751514118258},
    {-37.0737192244578, -9.185801561746},
    {-40.5285800942092, -9.3645012619056}
    };

    glColor3ub(64, 82, 59);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++) {
        glVertex2f(coordinates4[i][0], coordinates4[i][1]);
        }
    glEnd();

    GLfloat coordinates5[6][2] = {
    {-34.7416881373756, -9.1679315917301},
    {-29.1394525373736, -9.200693203426},
    {-28.156604186496, -8.2833680759403},
    {-28.975644478894, -7.0711884431913},
    {-34.4795952438083, -7.0384268314954},
    {-35.2658739245103, -8.4144145227239}
    };

    glColor3ub(64, 100, 59);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++) {
        glVertex2f(coordinates5[i][0], coordinates5[i][1]);
        }
    glEnd();

    GLfloat coordinates6[4][2] = {
    {-32.7759914356205, -6.9729036081035},
    {-29.9257312180756, -7.0056652197995},
    {-29.94307813727208, -6.2067648055982},
    {-32.7369656090538, -6.18338499441189}
    };

    glColor3ub(0,0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++) {
        glVertex2f(coordinates6[i][0], coordinates6[i][1]);
    }
    glEnd();

    GLfloat coordinates7[4][2] = {
    {-28.2041041253044, -8.0834751319424},
    {-23.5316569840892, -8.1170551393294},
    {-23.5487271750826, -7.6898257390928},
    {-28.5121775631867,-7.6384801661124}
    };

    glColor3ub(0,0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 4; i++) {
        glVertex2f(coordinates7[i][0], coordinates7[i][1]);
        }
    glEnd();


    tankwheel(-36.7486065009255, -13.0024423578731);
    tankwheel(-36.7486065009255 + 3, -13.0024423578731);
    tankwheel(-36.7486065009255 + 6, -13.0024423578731);
    tankwheel(-36.7486065009255 + 9, -13.0024423578731);
    tankwheel(-36.7486065009255 + 12, -13.0024423578731);

    glPushMatrix();
    glScalef(0.5,0.5,1);
    tankwheel(-45.7486065009255 , -25.0024423578731);
    glPopMatrix();
    glPushMatrix();
    glScalef(0.5,0.5,1);
    tankwheel(-77.7486065009255 , -25.0024423578731);
    glPopMatrix();
}


void car_body()
{
    glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-16.5001269759061,-3.7465120560524);
	glVertex2f(-14.5577980219702,0.2993710211187);
	glVertex2f(12.7911058600849,0.594989767384);
	glVertex2f(13.9993447375705,-3.6153961081491);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-17.1194056915354,-1.1066377491657);
	glVertex2f(-18.2360673428017,-1.1465185224252);
	glVertex2f(-18.3955904358397,3.5183396815327);
	glVertex2f(-16.8003595054593,3.7576243210898);
	glEnd();


	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-16.016214213392,6.5723286972352);
	glVertex2f(-9.6231436555839,6.6111382339383);
	glVertex2f(-9.8144093286997,2.2502808868993);
	glVertex2f(-16.6215160475773,2.167619221467);
	glEnd();

	glColor3ub(34, 34, 34);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-15.5086407355436,6.2097762130578);
	glVertex2f(-10.5416717023136,6.318541958311);
	glVertex2f(-10.6504374475668,3.2005905943856);
	glVertex2f(-15.7624274744678,3.2368458428033);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-15.9349108684035,-2.7608797487333);
	glVertex2f(-15.3629907469954,-1.4024831618164);
	glVertex2f(-18.1535926765462,-1.3455137676768);
	glVertex2f(-18.0388332726767,-2.7608797487333);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-16.2619373902682,-1.3797464025852);
	glVertex2f(-15.3629907469954,-1.4024831618164);
	glVertex2f(-14.5577980219702,0.2993710211187);
	glVertex2f(-14.9403293682016,0.9879274443353);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-9.8144093286997,0.9496743097122);
	glVertex2f(-10.5412188865395,0.1463584826261);
	glVertex2f(-14.5577980219702,0.2993710211187);
	glVertex2f(-14.9403293682016,0.9879274443353);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-9.8144093286997,0.9496743097122);
	glVertex2f(-10.5412188865395,0.1463584826261);
	glVertex2f(-8.4755496168895,-2.8756391526027);
	glVertex2f(-7.2131961743255,-2.8373860179796);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(12.6501012124336,-1.1078300165706);
	glVertex2f(14.165570596295,-1.1078300165706);
	glVertex2f(14.32250936893331,-2.2244916678369);
	glVertex2f(13,-2.3441339876154);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(4.6452755588507,-2.8373860179796);
	glVertex2f(7.3229949824711,1.2556993866974);
	glVertex2f(7.9350451364415,0.4523835596113);
	glVertex2f(5.754616462922,-2.9138922872259);
	glEnd();

	glColor3ub(32, 32, 32);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(7.3229949824711,1.2556993866974);
	glVertex2f(7.9350451364415,0.4523835596113);
	glVertex2f(12.4973092548281,0.4842877243956);
	glVertex2f(12.5254212912194,1.1791931174511);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(13.443496522175,-0.1979197289823);
	glVertex2f(12.7931932335814,-0.1979197289823);
	glVertex2f(12.4973092548281,0.4842877243956);
	glVertex2f(12.5254212912194,1.1791931174511);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-16.2619373902682,-1.3797464025852);
	glVertex2f(-16.7764798301128,-1.374248094561);
	glVertex2f(-16.6215160475773,2.167619221467);
	glVertex2f(-14.9403293682016,0.9879274443353);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-9.8144093286997,2.2502808868993);
	glVertex2f(-9.8144093286997,0.9496743097122);
	glVertex2f(-14.9403293682016,0.9879274443353);
	glVertex2f(-16.6215160475773,2.167619221467);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-9.8144093286997,0.9496743097122);
	glVertex2f(-7.2131961743255,-2.8373860179796);
	glVertex2f(4.6452755588507,-2.8373860179796);
	glVertex2f(7.3229949824711,1.2556993866974);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-9.8144093286997,0.9496743097122);
	glVertex2f(-9.8144093286997,2.2502808868993);
	glVertex2f(3.7654534625183,2.9005841754928);
	glVertex2f(7.3229949824711,1.2556993866974);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(12.5254212912194,1.1791931174511);
	glVertex2f(12,2);
	glVertex2f(3.7654534625183,2.9005841754928);
	glVertex2f(7.3229949824711,1.2556993866974);
	glEnd();

	glColor3ub(84, 99, 66);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(3.7654534625183,2.9005841754928);
	glVertex2f(1.3555059812599,6.3051131569531);
	glVertex2f(-9.6231436555839,6.6111382339383);
	glVertex2f(-9.8144093286997,2.2502808868993);
	glEnd();

	glColor3ub(96, 96, 96);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-9.0914617656041,6.1372657162223);
	glVertex2f(-4.7770872038934,6.1010104678046);
	glVertex2f(-4.4870452165515,3.0918248491324);
	glVertex2f(-9.0914617656041,3.0555696007146);
	glEnd();

	glColor3ub(96, 96, 96);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-3.1093457766774,6.0284999709691);
	glVertex2f(1.0600077913624,5.9559894741336);
	glVertex2f(2.4377072312364,3.0918248491324);
	glVertex2f(-3.036835279842,3.1280800975501);
	glEnd();

	glColor3ub(32,32,32);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-16.0188971017749,6.5039143270011);
	glVertex2f(1.1561906726442,6.40);

	glVertex2f(-16.8003595054593,2.0427510709308);
	glVertex2f(-16.8003595054593,0.6868047801074);
	glEnd();

	glColor3ub(32,32,32);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(3.1951291092882,2.7832270660941);
	glVertex2f(1.1561906726442,6.40);

	glVertex2f(3.1951291092882,2.7832270660941);
	glVertex2f(3.3449441853946,-1.8011142627603);

	glVertex2f(3.3449441853946,-1.8011142627603);
	glVertex2f(-3.5765123307189,-1.8910033084242);

	glVertex2f(-3.5765123307189,-1.8910033084242);
	glVertex2f(-3.8162164524891,6.5585669839742);

	glVertex2f(-4.1158466047018,6.5885299991955);
	glVertex2f(-4.1158466047018,-1.8910033084242);

	glVertex2f(-4.1158466047018,-1.8910033084242);
	glVertex2f(-7.4717043094841,-1.8910033084242);

	glVertex2f(-7.4717043094841,-1.8910033084242);
	glVertex2f(-9.6231436555839,0.9879);

	glVertex2f(-9.6231436555839,0.9879);
	glVertex2f(-9.6231436555839,6.6111382339383);

	glVertex2f(3.2250921245095,1.884336609456);
	glVertex2f(12.4537008126608,1.5247804268007);

	glVertex2f(12.4537008126608,1.5247804268007);
	glVertex2f(12,2);

	glVertex2f(5.3225031899984,1.7442626398985);
	glVertex2f(5.2537081070504,2.7201280826401);

	glVertex2f(2,-2);
	glVertex2f(2,-2.7898937650623);

	glEnd();

	glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; i++) {
        float angle = 2 * 3.1416 * i / 100;
        float x = 2.5 * cos(angle);
        float y = 2.5 * sin(angle);
        glVertex2f(x - 2, y + 1);
        }
    glEnd();
//star
	glColor3ub(0,0,0);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(-2, 1);
    for (int i = 0; i <= 10; i++) {
        float angle = i * 3.1416 / 5;
        float r =  (i % 2 == 0) ? 2.4 : 1.0;
        float x = r * cos(angle);
        float y = r * sin(angle);
        glVertex2f(x - 2 , y + 1);
        }

    glEnd();


	glPushMatrix();
	glTranslatef(-4,-10,0);
	glScalef(1,1,1);
	fire();
	glPopMatrix();
}
void car_Wheel0()
{
    glPushMatrix();
	glTranslatef(-12.23, -3.74,0);
    glRotatef(angel,0,0,1);
    glTranslatef(12.23, 3.74,0);

    glColor3ub(25, 25, 25);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float cx = -12.23;
            float cy = -3.74;
            float r=3.06;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cx , y+cy );
        }
    glEnd();


    glColor3ub(90, 90, 90);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float cx = -12.23;
            float cy = -3.74;
            float r=1.76;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cx , y+cy );
        }
    glEnd();


    glColor3ub(64,64,64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-12.65,-2.31);
	glVertex2f(-11.67,-2.31);
	glVertex2f(-12.21,-3.05);
	glEnd();

	glColor3ub(64,64,64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-12.719,-5.207);
	glVertex2f(-13.576,-4.536);
	glVertex2f(-12.719,-4.313);
	glEnd();

	glColor3ub(64,64,64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-10.99,-2.86);
	glVertex2f(-10.73,-3.853);
	glVertex2f(-11.51,-3.55);
	glEnd();

	glColor3ub(64,64,64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-10.99,-4.673);
	glVertex2f(-11.874,-5.20);
	glVertex2f(-11.78,-4.350);
	glEnd();

	glColor3ub(64,64,64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-13.799,-3.74);
	glVertex2f(-13.402,-2.76);
	glVertex2f(-12.9057,-3.480);
	glEnd();



	glColor3ub(64, 64, 64);
	glPointSize(10.0);
	glBegin(GL_POINTS);
	glVertex2f(-12.23, -3.74);
	glEnd();

	glPopMatrix();

}

void car_Wheel1()
{

	glTranslatef(9.93, -3.42, 0);
    glRotatef(angel, 0, 0, 1);
    glTranslatef(-9.93, +3.42, 0);

     glColor3ub(25, 25, 25);;
    glBegin(GL_POLYGON);
    float bombY = 45.0f;
    float bombX = -55.0f;
    bool bombDropped = false;
    bool exploded = false;
    int explosionTimer = 0;

    for(int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float cx = 9.93;
        float cy = -3.42;
        float r = 3.06;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    glColor3ub(90, 90, 90);
    glBegin(GL_POLYGON);
    for(int i = 0; i < 200; i++)
    {
        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;
        float cx = 9.93;
        float cy = -3.42;
        float r = 1.76;
        float x = r * cos(A);
        float y = r * sin(A);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    glColor3ub(64, 64, 64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(9.51, -1.99);
	glVertex2f(10.49, -1.99);
	glVertex2f(9.95, -2.73);
    glEnd();

    glColor3ub(64, 64, 64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(9.441, -4.887);
	glVertex2f(8.584, -4.216);
	glVertex2f(9.441, -4.033);
    glEnd();

    glColor3ub(64, 64, 64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(11.17, -2.54);
	glVertex2f(11.43, -3.533);
	glVertex2f(10.65, -3.23);
    glEnd();

    glColor3ub(64, 64, 64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(11.17, -4.353);
	glVertex2f(10.286, -4.88);
	glVertex2f(10.38, -4.03);
    glEnd();

    glColor3ub(64, 64, 64);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(8.361, -3.42);
	glVertex2f(8.758, -2.44);
	glVertex2f(9.2543, -3.16);
    glEnd();

    glColor3ub(64, 64, 64);
    glPointSize(10.0);
    glBegin(GL_POINTS);
	glVertex2f(9.93, -3.42);
    glEnd();

    glPopMatrix();
}


void river()
{
    glColor3ub(153, 204, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,-40);
	glVertex2f(-70,-24);
	glVertex2f(70, -24);
	glVertex2f(70, -40);
	glEnd();
}

void wall()
{
    glColor3ub(204,102,0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,-24);
	glVertex2f(-70,-21.5);
	glVertex2f(-60, -21.5);
	glVertex2f(-60, -24);
	glEnd();

	glColor3ub(255,178,102);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-60,-24);
	glVertex2f(-60,-21.5);
	glVertex2f(-50,-21.5);
	glVertex2f(-50, -24);
	glEnd();
}

void footpath()
{
    glColor3ub(255, 255, 153);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,-22);
	glVertex2f(-70,-18);
	glVertex2f(+70, -18);
	glVertex2f(+70, -22);
	glEnd();

	glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(-70, -19.75);
    glVertex2f(+70, -19.75);
	glEnd();
}

void footpathborder()
{
    glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(-65, -18);
    glVertex2f(-65, -21.5);
	glEnd();
}



void road()
{
    glColor3ub(80,80,80);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,-18);
	glVertex2f(-70,-9);
	glVertex2f(70, -9);
	glVertex2f(70, -18);
	glEnd();

	glColor3ub(111, 106, 78);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,-9);
	glVertex2f(-70,-7);
	glVertex2f(70, -7);
	glVertex2f(70, -9);
	glEnd();

	glColor3ub(80,80,80);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,-7);
	glVertex2f(-70,+2);
	glVertex2f(70, +2);
	glVertex2f(70, -7);
	glEnd();


	glColor3ub(153, 179, 204);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-70,+2);
	glVertex2f(-70,60);
	glVertex2f(70, 60);
	glVertex2f(70, +2);
	glEnd();


}

void roadDivider()
{
    glColor3ub(255, 255, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-62,-14);
	glVertex2f(-62,-13);
	glVertex2f(-50, -13);
	glVertex2f(-50, -14);
	glEnd();

	glColor3ub(255, 255, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-62,-3);
	glVertex2f(-62,-2);
	glVertex2f(-50, -2);
	glVertex2f(-50, -3);
	glEnd();
}

void Tree()
{
//Tree
    glColor3ub(193, 76, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(16.35, -18);
	glVertex2f(17.27, -18);
	glVertex2f(17.27, -12.38);
	glVertex2f(16.35, -12.28);
	glEnd();

	glColor3ub(0, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(12.72, -12.38);
	glVertex2f(20.76, -12.38);
	glVertex2f(19.23, -10.4);
	glVertex2f(14.29, -10.4);
	glEnd();

	glColor3ub(0, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(13.14, -10.4);
	glVertex2f(20.41, -10.4);
	glVertex2f(19.28, -8.76);
	glVertex2f(14.22, -8.76);
	glEnd();

	glColor3ub(0, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(13.21, -8.76);
	glVertex2f(20.04, -8.76);
	glVertex2f(16.64, -2.56);
	glEnd();

	glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(19.28, -8.76);
	glVertex2f(14.22, -8.76);

	glVertex2f(19.23, -10.4);
	glVertex2f(14.29, -10.4);

	glVertex2f(17.27, -12.38);
	glVertex2f(16.35, -12.28);
	glEnd();

}

void bench()
{
    glColor3ub(102, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(15.26, -16.10);
	glVertex2f(24.28, -16.10);
	glVertex2f(23.54, -15.60);
	glVertex2f(15.93, -15.60);
	glEnd();

    glColor3ub(0,0,0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(16.04, -14.25);
	glVertex2f(16.04, -15.62);

	glVertex2f(19.72, -14.25);
	glVertex2f(19.72, -15.62);

	glVertex2f(23.42, -14.25);
	glVertex2f(23.42, -15.62);
	glEnd();

	glColor3ub(0,0,0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2f(17.90, -14.25);
	glVertex2f(17.90, -15.62);

	glVertex2f(21.60, -14.25);
	glVertex2f(21.60, -15.62);
	glEnd();

	glColor3ub(102, 51, 0);
    glLineWidth(8.0);
    glBegin(GL_LINES);
    glVertex2f(15.84,-14.23);
    glVertex2f(23.60 ,-14.23);

	glVertex2f(15.84, -14.63);
	glVertex2f(23.60, -14.63);

	glVertex2f(15.84, -15.03);
	glVertex2f(23.60, -15.03);

	glVertex2f(15.25, -16.18);
	glVertex2f(24.30, -16.18);
	glEnd();

//bench leg
    glColor3ub(0,0,0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(15.27, -16.31);
	glVertex2f(24.28, -16.31);

	glVertex2f(19.75, -16.33);
	glVertex2f(19.75, -17.15);

    glVertex2f(15.43, -16.32);
	glVertex2f(15.43, -17.88);

	glVertex2f(16.12, -16.32);
	glVertex2f(16.12, -17.11);

	glVertex2f(15.50, -17.27);
	glVertex2f(16.15, -16.70);


	glVertex2f(24.10, -16.31);
	glVertex2f(24.10, -17.87);

    glVertex2f(23.33, -16.34);
	glVertex2f(23.33, -17.54);

    glVertex2f(23.32, -16.77);
	glVertex2f(24.02, -17.32);

    glVertex2f(23.62, -17.00);
	glVertex2f(15.87, -17.00);

    glVertex2f(19.85, -16.33);
	glVertex2f(19.85, -17.87);
	glEnd();

	glColor3ub(0,0,0);
    glLineWidth(1.0);
    glBegin(GL_LINES);
    glVertex2f(15.26, -16.10);
	glVertex2f(24.28, -16.10);

	glVertex2f(15.77, -15.75);
	glVertex2f(23.73, -15.75);

    glVertex2f(24.02, -15.95);
	glVertex2f(15.53, -15.95);
	glEnd();

}




void Building()
{

    glColor3ub(4, 73, 132);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-8.80, 16.28);
	glVertex2f(10.95, 16.28);
	glVertex2f(10.95, -17.35);
	glVertex2f(-8.80, -17.35);
	glEnd();

    glColor3ub(4, 73, 132);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-0.89, -17.90);
	glVertex2f(2.99, -17.90);
	glVertex2f(2.99, -8.75);
	glVertex2f(-0.89, -8.75);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-7.12, -15.04);
	glVertex2f(-2.94, -15.04);
	glVertex2f(-2.94, -8.98);
	glVertex2f(-7.12, -8.98);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(4.86, -15.04);
	glVertex2f(9.04, -15.04);
	glVertex2f(9.04, -8.98);
	glVertex2f(4.86, -8.98);
	glEnd();
//1
	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-5.95, -2.33);
	glVertex2f(-3.93, -2.33);
	glVertex2f(-3.93, -5.14);
	glVertex2f(-5.95, -5.14);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-0.13, -2.33);
	glVertex2f(1.89, -2.33);
	glVertex2f(1.89, -5.14);
	glVertex2f(-0.13, -5.14);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(5.69, -2.33);
	glVertex2f(7.74, -2.33);
	glVertex2f(7.74, -5.14);
	glVertex2f(5.69, -5.14);
	glEnd();
//2
	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-5.95, 3.52);
	glVertex2f(-3.93, 3.52);
	glVertex2f(-3.93, 0.79);
	glVertex2f(-5.95, 0.79);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-0.13, 3.52);
	glVertex2f(1.89, 3.52);
	glVertex2f(1.89, 0.79);
	glVertex2f(-0.13, 0.79);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(5.69, 3.52);
	glVertex2f(7.74, 3.52);
	glVertex2f(7.74, 0.79);
	glVertex2f(5.69, 0.79);
	glEnd();
//3
	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-5.95, 9);
	glVertex2f(-3.93, 9);
	glVertex2f(-3.93, 6.18);
	glVertex2f(-5.95, 6.18);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-0.13, 9);
	glVertex2f(1.89, 9);
	glVertex2f(1.89, 6.18);
	glVertex2f(-0.13, 6.18);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(5.69, 9);
	glVertex2f(7.74, 9);
	glVertex2f(7.74, 6.18);
	glVertex2f(5.69, 6.18);
	glEnd();

//4
    glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-5.95, 14.14);
	glVertex2f(-3.93, 14.14);
	glVertex2f(-3.93, 11.40);
	glVertex2f(-5.95, 11.40);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-0.13, 14.14);
	glVertex2f(1.89, 14.14);
	glVertex2f(1.89, 11.40);
	glVertex2f(-0.13, 11.40);
	glEnd();

	glColor3ub(204, 229, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(5.69, 14.14);
	glVertex2f(7.74, 14.14);
	glVertex2f(7.74, 11.40);
	glVertex2f(5.69, 11.40);
	glEnd();

	glColor3ub(255,128,0);
    glLineWidth(7.0);
    glBegin(GL_LINES);
	glVertex2f(-9.55, -6.90);
	glVertex2f(11.80, -6.90);
	glEnd();

	glColor3ub(255,204,153);
    glLineWidth(4.0);
    glBegin(GL_LINES);
	glVertex2f(-9.35, -6.90);
	glVertex2f(11.60, -6.90);
	glEnd();

    glColor3ub(255,128,0);
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(-9.40, 15.65);
	glVertex2f(11.65, 15.65);
	glEnd();

    glColor3ub(255,204,153);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(-9.25, 15.65);
	glVertex2f(11.50, 15.65);
	glEnd();

    glColor3ub(255,128,0);
    glLineWidth(13.0);
    glBegin(GL_LINES);
	glVertex2f(-9.55, 16.50);
	glVertex2f(11.80, 16.50);
	glEnd();

	glColor3ub(255,204,153);
    glLineWidth(10.0);
    glBegin(GL_LINES);
	glVertex2f(-9.35, 16.50);
	glVertex2f(11.60, 16.50);
	glEnd();

	glColor3ub(4, 73, 132);
    glLineWidth(15.0);
    glBegin(GL_LINES);
	glVertex2f(-9.50, -17.65);
	glVertex2f(11.55, -17.65);
	glEnd();

	glColor3ub(4, 73, 132);
    glLineWidth(2.0);
    glBegin(GL_LINES);
	glVertex2f(-9.50, -17.65);
	glVertex2f(11.55, -17.65);
	glEnd();

	glColor3ub(192, 192, 192);
    glLineWidth(3.0);
    glBegin(GL_LINES);
//1
	glVertex2f(-6.15, -2.13);
	glVertex2f(-3.73, -2.13);

	glVertex2f(-6.35, -1.93);
	glVertex2f(-3.53, -1.93);

	glVertex2f(-6.15, 14.34);
	glVertex2f(-3.73, 14.34);

	glVertex2f(-6.35, 14.54);
	glVertex2f(-3.53, 14.54);

	glVertex2f(-6.15, 3.72);
	glVertex2f(-3.73, 3.72);

	glVertex2f(-6.35, 3.92);
	glVertex2f(-3.53, 3.92);

	glVertex2f(-6.15, 9.20);
	glVertex2f(-3.73, 9.20);

	glVertex2f(-6.35, 9.40);
	glVertex2f(-3.53, 9.40);
//2
	glVertex2f(-0.33, -2.13);
	glVertex2f(2.09, -2.13);

	glVertex2f(-0.53, -1.93);
	glVertex2f(2.29, -1.93);

	glVertex2f(-0.33, 14.34);
	glVertex2f(2.09, 14.34);

	glVertex2f(-0.53, 14.54);
	glVertex2f(2.29, 14.54);

	glVertex2f(-0.33, 3.72);
	glVertex2f(2.09, 3.72);

	glVertex2f(-0.53, 3.92);
	glVertex2f(2.29, 3.92);

	glVertex2f(-0.33, 9.20);
	glVertex2f(2.09, 9.20);

	glVertex2f(-0.53, 9.40);
	glVertex2f(2.29, 9.40);

	//3
	glVertex2f(5.49, -2.13);
	glVertex2f(7.94, -2.13);

	glVertex2f(5.29, -1.93);
	glVertex2f(8.14, -1.93);

	glVertex2f(5.49, 14.34);
	glVertex2f(7.94, 14.34);

	glVertex2f(5.29, 14.54);
	glVertex2f(8.14, 14.54);

	glVertex2f(5.49, 3.72);
	glVertex2f(7.94, 3.72);

	glVertex2f(5.29, 3.92);
	glVertex2f(8.14, 3.92);

	glVertex2f(5.49, 9.20);
	glVertex2f(7.94, 9.20);

	glVertex2f(5.29, 9.40);
	glVertex2f(8.14, 9.40);
	glEnd();

    // Charcoal black
	glColor3ub(30, 30, 30);
    glBegin(GL_POLYGON);
    glVertex2f(-5, 5);
    glVertex2f(-3, 6);
    glVertex2f(-4, 4);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(6, 3);
    glVertex2f(7.5, 4);
    glVertex2f(7, 2);
    glEnd();

    // Broken window
    glColor3ub(20, 20, 20);
    glLineWidth(1.5);
    glBegin(GL_LINES);
    glVertex2f(-5.2, -2.3);
    glVertex2f(-4.6, -5.0);

    glVertex2f(-5.9, -5.0);
    glVertex2f(-3.9, -2.3);
    glEnd();

    // Wall cracks
    glColor3ub(60, 60, 60);
    glLineWidth(2);
    glBegin(GL_LINE_STRIP);
    glVertex2f(2.5, 5);
    glVertex2f(2.2, 3.5);
    glVertex2f(3, 2.2);
    glVertex2f(2.6, 1);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-2, 10);
    glVertex2f(-1.8, 9);
    glVertex2f(-2.5, 7.5);
    glEnd();


}

void lampPost()
{
    //lamppost
    glColor3ub(153, 76, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(24.95, -17.96);
	glVertex2f(26.78, -17.96);
	glVertex2f(26.40, -16.55);
	glVertex2f(25.34, -16.55);
	glEnd();

	glColor3ub(204, 204, 9);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(22.77, -5.17);
	glVertex2f(23.71, -5.17);
	glVertex2f(24.30, -7.1);
	glVertex2f(22.32, -7.1);
	glEnd();

	glColor3ub(192, 192, 192);
    glLineWidth(6.0);
    glBegin(GL_LINES);
    glVertex2f(25.88, -16.55);
	glVertex2f(25.88, -4.86);
	glEnd();

	glColor3ub(192, 192, 192);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(26.43, -6.02);
	glVertex2f(22.86, -4.50);
	glEnd();

	glColor3ub(192, 192, 192);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    glVertex2f(23.29, -4.65);
	glVertex2f(23.29, -5.17);
	glEnd();
}



void plane()
{
    glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-65.3473456957115,43.4434612394056);
	glVertex2f(-65.1790212281826,42.9758932740477);
	glVertex2f(-60.7277741979757,42.6018389017614);
	glVertex2f(-61.9808563451348,44.4347053259642);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-60.7277741979757,42.6018389017614);
	glVertex2f(-61.9808563451348,44.4347053259642);
	glVertex2f(-43.7083002589494,48.5493034211135);
	glVertex2f(-43.446462198349,45.9309228151094);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
	glVertex2f(-43.7083002589494,48.5493034211135);
	glVertex2f(-43.446462198349,45.9309228151094);
	glVertex2f(-42.2307854884185,48.0630327371413);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-43.446462198349,45.9309228151094);
	glVertex2f(-42.2307854884185,48.0630327371413);
	glVertex2f(-41.37046043216,47.7076810834693);
	glVertex2f(-41.2395414018598,47.2214103994971);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-54.9673368647668,43.6678938627773);
    glVertex2f(-51.5634420769615,44.5282189190358);
    glVertex2f(-59.3437730205165,37.5521048758965);
    glVertex2f(-59.9048545789459,37.6830239061967);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-51.8376396320996,46.8040599336152);
    glVertex2f(-53.3402003453214,49.5031420704435);
    glVertex2f(-54.2379308388085,49.4844393518292);
    glVertex2f(-53.8444149900903,46.3126047439032);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-64.6553451069818,43.0694068671193);
    glVertex2f(-62.8037759641647,43.4434612394056);
    glVertex2f(-65.2351293840256,41.7415138455029);
    glVertex2f(-66.1889680333556,41.4796757849025);
	glEnd();

	glColor3ub(64, 82, 59);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-64.5992369511389,43.7614074558489);
    glVertex2f(-61.9559219367659,44.4292394409352);
    glVertex2f(-66.0393462844411,46.6416261224534);
    glVertex2f(-66.9557794965425,46.3423826246243);
	glEnd();


}

void planeWindow()
{
    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-59.3076128980207,44.1954676944567);
    glVertex2f(-59.2096064809454,43.6945551363733);
    glVertex2f(-59.6,43.6);
    glVertex2f(-59.7072723319986,44.1025890936027);
	glEnd();
}

void allPlaneWindow()
{
    glPushMatrix();
    for(int i=0; i<9; i++)
    {
        glTranslatef(1.2, 0.27, 0);
        planeWindow();
    }
    glTranslatef(1.2+3.5, 0.27+0.7, 0);
    planeWindow();
    glPopMatrix();


}

void planeDoor()
{
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-44.8166712995643,46.1419406472307);
    glVertex2f(-45.0748235926864,47.3294411955924);
    glVertex2f(-45.9525413893016,47.1745498197191);
    glVertex2f(-45.6427586375551,45.9354188127331);
	glEnd();
}



void circleCloud1()
{
    glColor3ub(255, 255, 255);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float cx = -11.4252;
            float cy = 53.79;
            float r=3;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cx , y+cy );
        }
    glEnd();
}

void cloud1()
{
    circleCloud1();

    glPushMatrix();
    glTranslatef(-4, 0, 0);
    circleCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-4, 0, 0);
    circleCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-2, -4, 0);
    circleCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-6, -3, 0);
    circleCloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(2, -3, 0);
    circleCloud1();
    glPopMatrix();
}

void cloud2()
{
    glPushMatrix();
    glTranslatef(50, -20, 0);
    glScalef(1.3, 1.3, 0);
    cloud1();
    glPopMatrix();
}

void cloud3()
{
    glPushMatrix();
    glTranslatef(-110, 7, 0);
    cloud2();
    glPopMatrix();
}


void sun()
{
    glColor3ub(253, 184, 19);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float cx = -7.4252;
            float cy = 55.79;
            float r=5;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cx , y+cy );
        }
    glEnd();
}




void window()
{
    glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(39.5298282012125,19.6525984180035);
    glVertex2f(42.8727420197046,19.6581219511856);
    glVertex2f(42.8782655528868,17.0776512875435);
    glVertex2f(39.5298282012125,17.0724767764828);
	glEnd();
}
void building1()
{

    glColor3ub(102, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(52.1122346663419,31.7932968199385);
    glVertex2f(40.6675059643112,26.3967847026966);
    glVertex2f(63.5911610499133,26.4432829888742);
	glEnd();

	glColor3ub(80, 80, 80);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(41.6337277601487,26.209913061965);
    glVertex2f(62.4716648018511,26.2058641452302);
    glVertex2f(62.4376158851162,21.9257006366446);
    glVertex2f(41.5996788434139,21.857602803175);
	glEnd();

	glColor3ub(80, 80, 80);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(36.1158567340298,20.755651119294);
    glVertex2f(35.8891056551843,8.9079072496147);
    glVertex2f(67.9743833118295,8.964595019326);
    glVertex2f(68.0877588512523,20.6422755798712);
	glEnd();

	glColor3ub(102, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(52.6119977200435,19.5652079553549);
    glVertex2f(44.617519220669,15.3873080990746);
    glVertex2f(60.8688700334726,15.3873080990746);
	glEnd();

	glColor3ub(0, 0 , 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(45.7703357861269,15.2671369840406);
    glVertex2f(45.8365221025527,8.8470642907432);
    glVertex2f(59.6694622355345,8.9132506071689);
    glVertex2f(59.8264889807211,15.2909173047937);
	glEnd();

	glColor3ub(102, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(34.6800685834762,21.7685488044511);
    glVertex2f(34.6809375723887,20.8560773318755);
    glVertex2f(69.3539845413504,20.8546916127004);
    glVertex2f(69.3539845413504,21.7685488044511);
	glEnd();

	glColor3ub(102, 51, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(34.7118538980109,7.9411577900311);
    glVertex2f(69.387535486509,7.9480399129678);
    glVertex2f(69.3418090588216,8.788314116589);
    glVertex2f(34.7120328784575,8.808568299232);
	glEnd();

	window();

	glPushMatrix();
    glTranslatef(0, -3.5, 0);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -7, 0);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.5, 0, 0);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.5, -3.5, 0);
    window();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(22.5, -7, 0);
    window();
    glPopMatrix();

   glColor3ub(40, 40, 40);
    glBegin(GL_POLYGON);
    glVertex2f(50, 25);
    glVertex2f(52, 26);
    glVertex2f(51, 23.5);
    glEnd();



    // Side wall cracks
    glColor3ub(80, 80, 80);
    glLineWidth(2.5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(45, 18);
    glVertex2f(46.5, 16);
    glVertex2f(45.5, 14);
    glVertex2f(46, 12);
    glEnd();

    // Bullet holes
    glColor3ub(25, 25, 25);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2f(47, 10);
    glVertex2f(49, 9.5);
    glVertex2f(43.5, 14);
    glVertex2f(50.8, 16.5);
    glEnd();

}

void building2()
{
    glColor3ub(121, 122, 82);
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
        {
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float cx = 1.75;
            float cy = 26.85;
            float r=8;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+cx , y+cy );
        }
    glEnd();

    glColor3ub(121, 122, 82);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-17.6249568191571,28.284282932764);
    glVertex2f(21.2770303367225,28.359238592023);
    glVertex2f(21.1271190182028,9.0206785029748);
    glVertex2f(-17.3251341821176,8.7958115251952);
	glEnd();

	glColor3ub(107, 157, 210);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-14.6050143423134,24.4620920551465);
    glVertex2f(-2.1687153812589,24.6877962105195);
    glVertex2f(-2.0719212758288,8.9482395873327);
    glVertex2f(-14.5146424816277,8.888274665859);
	glEnd();

	glColor3ub(107, 157, 210);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(5.4919195777846,24.7221934989191);
    glVertex2f(17.8530029448235,24.7221934989191);
    glVertex2f(18.1227840115081,9.2631669578174);
    glVertex2f(5.6641583326169,9.0909278931323);
	glEnd();

	glColor3ub(0, 0, 0);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0531651901033,14.2006868121243);
    glVertex2f(-1.110578211665,8.9761018500089);
    glVertex2f(4.8603760307529,9.0335148715706);
    glVertex2f(4.6307239445061,14.3155128552477);
	glEnd();

	glPushMatrix();
    glTranslatef(-52.6, 4, 0);
    window();
    glTranslatef(6, 0, 0);
    window();
    glTranslatef(14, 0, 0);
    window();
    glTranslatef(6, 0, 0);
    window();
    glTranslatef(0, -4, 0);
    window();
    glTranslatef(-6, 0, 0);
    window();
    glTranslatef(-14, 0, 0);
    window();
    glTranslatef(-6, 0, 0);
    window();
    glTranslatef(0, -4, 0);
    window();
    glTranslatef(6, 0, 0);
    window();
    glTranslatef(14, 0, 0);
    window();
    glTranslatef(6, 0, 0);
    window();
    glTranslatef(0, -4, 0);
    window();
    glTranslatef(-6, 0, 0);
    window();
    glTranslatef(-14, 0, 0);
    window();
    glTranslatef(-6, 0, 0);
    window();
    glTranslatef(13, 11.5, 0);
    window();
    glTranslatef(0, -4.5, 0);
    window();
    glPopMatrix();

    glColor3ub(255, 0 , 0);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glVertex2f(-2.4,30.5);
    glVertex2f(5.4,30.5);
    glEnd();

    glColor3ub(255, 0 , 0);
    glLineWidth(7.0);
    glBegin(GL_LINES);
    glVertex2f(1.4,34);
    glVertex2f(1.4,27);
    glEnd();


    glColor3ub(35, 20, 20);
    glBegin(GL_POLYGON);
    glVertex2f(-15, 24);
    glVertex2f(-13.5, 25.2);
    glVertex2f(-14.2, 22.8);
    glVertex2f(-16, 22.5);
    glEnd();

    glColor3ub(60, 60, 60);
    glLineWidth(3);
    glBegin(GL_LINE_STRIP);
    glVertex2f(-1, 28);
    glVertex2f(-0.5, 26.5);
    glVertex2f(0.5, 25.5);
    glVertex2f(0, 24);
    glVertex2f(1.2, 22);
    glVertex2f(0.5, 21);
    glEnd();


    glColor3ub(70, 70, 70);
    glBegin(GL_POLYGON);
    glVertex2f(16, 18);
    glVertex2f(18.5, 19);
    glVertex2f(17.5, 15.5);
    glVertex2f(15.8, 16);
    glEnd();


    glColor3ub(20, 20, 20);
    glLineWidth(1.5);

    glBegin(GL_LINES);
    glVertex2f(14.8, 22.5);
    glVertex2f(17.1, 20.5);
    glVertex2f(17.1, 22.5);
    glVertex2f(14.8, 20.5);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-13.5, 18.5);
    glVertex2f(-11.5, 16.5);
    glVertex2f(-11.5, 18.5);
    glVertex2f(-13.5, 16.5);
    glEnd();


    glColor3ub(10, 10, 10);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(-8, 24.5);
    glVertex2f(-4, 22.8);
    glVertex2f(3, 21.3);
    glVertex2f(5, 19.5);
    glVertex2f(7, 18.2);
    glVertex2f(10, 16.7);
    glVertex2f(13, 14.2);
    glEnd();


    glColor3ub(90, 90, 90);
    glLineWidth(2.5);
    glBegin(GL_LINE_STRIP);
    glVertex2f(3.5, 34.2);
    glVertex2f(4.0, 33.0);
    glVertex2f(3.3, 32.1);
    glVertex2f(4.5, 31.0);
    glEnd();
}



void metroLine()
{
    glColor3ub(128, 128, 128);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-67.59887650939,5.177642450919);
    glVertex2f(-64.46742121004,5.177642450919);
    glVertex2f(-64.5132336387313,-8.02739417);
    glVertex2f(-67.6345481917248,-8.02739417);
	glEnd();

	glColor3ub(128, 128, 128);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-70.59887650939,5.177642450919);
    glVertex2f(70.46742121004,5.177642450919);
    glVertex2f(70.5132336387313, 7.17);
    glVertex2f(-70.6345481917248, 7.17);
	glEnd();

}
void matroWindow()
{
    glColor3ub(120, 120, 120);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-24.3012564374519, 8.0028316993385);
    glVertex2f(-24.303138525056, 6.8211989687171);
    glVertex2f(-22.9683311812059, 6.8211989687171);
    glVertex2f(-22.9683311812059, 8.0028316993385);
    glEnd();


    glColor3ub(50, 50, 50);
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(-23.5, 7.5);
    glVertex2f(-23.0, 7.0);
    glVertex2f(-23.0, 7.0);
    glVertex2f(-22.5, 7.5);
    glEnd();
}

void matroBogi()
{
    glColor3ub(44, 49, 51);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-30,5.10);
    glVertex2f(-8.0786877980723,5.245487429652);
    glVertex2f(-8.0786877980723,9.3139413989026);
    glVertex2f(-29.8292686336812,9.3921808983112);
	glEnd();

	glColor3ub(255, 255, 255);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-29.8510842311116,5.5929897580858);
    glVertex2f(-29.8091174109043,6.6141823831301);
    glVertex2f(-8.6040533564617,6.6486496140772);
    glVertex2f(-8.5863357748422,5.5501595536691);
	glEnd();

	glColor3ub(69,88,166);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-8.5863357748422,5.5501595536691);
    glVertex2f(-8.5863357748422,6.2234276552095);
    glVertex2f(-28.6690843217404,6.185703081771);
    glVertex2f(-29.5452026580571,5.5672666090769);
	glEnd();

	glColor3ub(69,88,166);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-29.8200633125878,8.8827732543536);
    glVertex2f(-29.7857057307715,8.2471579907514);
    glVertex2f(-8.588626806381,8.2675214664698);
    glVertex2f(-8.588626806381,9.0081694411088);
	glEnd();

	glColor3ub(120, 120, 120);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-27.2572203516095,8.0247137869426);
    glVertex2f(-25.0908936788036,8.0684779621508);
    glVertex2f(-25.1565399416159,5.6395662380957);
    glVertex2f(-27.3009845268177,5.6176841504916);
	glEnd();

	glColor3ub(50, 50, 50);
    glLineWidth(2);

    glBegin(GL_LINES);
    glVertex2f(-26.0, 7.5);
    glVertex2f(-25.5, 7.0);

    glVertex2f(-25.7, 7.3);
    glVertex2f(-25.2, 6.8);

    glVertex2f(-26.5, 6.7);
    glVertex2f(-26.2, 6.2);

    glVertex2f(-27.0, 6.0);
    glVertex2f(-27.3, 6.5);

    glVertex2f(-25.5, 5.9);
    glVertex2f(-26.0, 5.5);
    glEnd();

    for(int i=0; i<15; i+=2)
    {
    glPushMatrix();
    glTranslatef(i,0,0);
    matroWindow();
    glPopMatrix();
    }

}

void matroTrain()
{
    glColor3ub(44, 49, 51);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-30,5.10);
    glVertex2f(-29.8292686336812,9.3921808983112);
    glVertex2f(-32.5714541350302,5.302395944369);
	glEnd();

	glColor3ub(120, 120, 120);
    glLineWidth(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(-30.5708878473668,8.2815000901287);
    glVertex2f(-31.4406992767856,7.237726374826);
    glVertex2f(-31.3319728481083,6.6723489457038);
    glVertex2f(-30.396925561483,7.3247075177679);
	glEnd();

	matroBogi();

	glPushMatrix();
    glTranslatef(22.2,0,0);
    matroBogi();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-33.5,0,0);
    glScalef(0.6,0.6,1);
    fire();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(3,1,0);
    glScalef(0.5,0.5,1);
    fire();
    glPopMatrix();
}






void drawBomb()
{
    if (bombDropped && !exploded) {
        glColor3ub(50, 50, 50);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.1416 / 180;
            float x = 1.2 * cos(angle);
            float y = 1.5 * sin(angle);
            glVertex2f(x + bombX-40, y + bombY);
        }
        glEnd();
    }
}

void drawExplosion()
{
    if (exploded) {
        glColor3ub(237, 21, 0);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.1416 / 180;
            float r = 5.0 + 0.5 * sin(i * 10 * 3.1416 / 180);
            float x = r * cos(angle);
            float y = r * sin(angle);
            glVertex2f(x + bombX-40, y + bombY + 9);
        }
        glEnd();

        glColor3ub(254, 182, 16);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.1416 / 180;
            float r = 3.0 + 0.5 * sin(i * 10 * 3.1416 / 180);
            float x = r * cos(angle);
            float y = r * sin(angle);
            glVertex2f(x + bombX-40, y + bombY + 9);
        }
        glEnd();
    }
}






void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);

    river();

    road();
    drawRoadCrack(-30, -14);
    drawRoadCrack(-10, -14);
    drawRoadCrack(15, -14);
    drawRoadCrack(40, -14);
    drawRoadCrack(-20, -13);
    drawRoadCrack(0, -13.5);
    drawRoadCrack(20, -13.2);
    for (int i = -60; i <= 60; i += 20) {
        drawRoadCrack(i, -3.5 + ((i % 30) / 10.0));
    }


    for(int i=0; i<141; i+=24)
    {
        glPushMatrix();
        glTranslatef(i,0,0);
        roadDivider();
        glPopMatrix();
    }

    footpath();
    glPushMatrix();
    glTranslatef(0,24,0);
    footpath();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-106,-1,0);
    building1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-29,19,0);
    glScalef(1, 0.70, 0);
    Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(61,20.1,0);
    glScalef(0.8, 0.7, 0);
    Building();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-14,-1,0);
    building1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0,-1.9,0);
    building2();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-21,0.5,0);
    glScalef(1.3,1.3,1);
    fire();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-48.5,10.3,0);
    glScalef(0.5,0.5,1);
    fire();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-34.5,17.3,0);
    glScalef(0.5,0.5,1);
    fire();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20,-7,0);
    glScalef(1.2,2,1);
    fire();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-75,-5,0);
    glScalef(1,1.8,1);
    fire();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(44,-20,0);
    glScalef(1,2.3,1);
    fire();
    glPopMatrix();



    for(int i=0; i<141; i+=4)
    {
        glPushMatrix();
        glTranslatef(i,24,0);
        footpathborder();
        glPopMatrix();
    }

    for(int i=0; i<141; i+=38)
    {
          glPushMatrix();
          glTranslatef(-75+i,20,0);
          lampPost();
          glPopMatrix();
    }



    glPushMatrix();
    glTranslatef(move1-60,-2,0);
    glScalef(0.5,0.5,0);
    car_body();
    car_Wheel0();
    car_Wheel1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(move1+50,-0.5,0);
    glScalef(0.5,0.5,0);
    car_body();
    car_Wheel0();
    car_Wheel1();
    glPopMatrix();

    for(int i=0; i<141; i+=25)
    {
        glPushMatrix();
        glTranslatef(i, 0, 0);
        metroLine();
        glPopMatrix();
    }


    glPushMatrix();
    glTranslatef(move2-20,-3.1, 0);
    glScalef(1,1,0);
    tank();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(move2+20,0, 0);
    glScalef(0.9,0.9,0);
    tank();
    glPopMatrix();

    for(int i=0; i<141; i+=38)
    {
          glPushMatrix();
          glTranslatef(-75+i,-1,0);
          lampPost();
          glPopMatrix();
    }


    for(int i=20; i<141; i+=20)
    {
        glPushMatrix();
        glTranslatef(i,0,0);
        wall();
        glPopMatrix();
    }

    for(int i=0; i<141; i+=4)
    {
        glPushMatrix();
        glTranslatef(i,0,0);
        footpathborder();
        glPopMatrix();
    }


    for(int i=0; i<141; i+=40)
    {
    glPushMatrix();
    glTranslatef(-75+i, -3, 0);
    bench();
    glPopMatrix();
    }

    for(int i=0; i<141; i+=20)
    {
        glPushMatrix();
        glTranslatef(-80.85+i,-3.5,0);
        Tree();
        glPopMatrix();
    }

    glPushMatrix();
    glTranslatef(planeMoveX, planeMoveY, 0);
    glScalef(1, 1, 1);
    plane();
    planeWindow();
    allPlaneWindow();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-1.2+planeMoveX, -0.5+planeMoveY, 0);
    planeDoor();
    glPopMatrix();

    glPushMatrix();
    drawBomb();
    drawExplosion();
    glPopMatrix();


    sun();

    glPushMatrix();
    glTranslatef(cloudMoveX,0,0);
    cloud1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudMoveX,0,0);
    cloud2();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(cloudMoveX,0,0);
    cloud3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(matroMove, 0, 0);
    glScalef(1.4, 1.2, 0);
    matroTrain();
    glPopMatrix();



    glutSwapBuffers();
    glFlush();

}


void update(int value)
{
    angel-=1.0f;

    move1+=0.15;
    move2+=0.06;
    planeMoveX+=0.05;
    planeMoveY+=0.005;
    matroMove-=0.17;

    cloudMoveX += -0.015f;

    if (cloudMoveX > 130) {
        cloudMoveX = -130;
    }

    if(planeMoveX > 130)
    {
        planeMoveX = -40;
    }

    if(planeMoveY > 130)
    {
        planeMoveY = -80;
    }

    if(move1>130)
    {
        move1=-40;
    }

    if(move2>130)
    {
        move2=-50;
    }

    if(matroMove<-90)
    {
        matroMove=100;
    }

    if (bombDropped && !exploded) {
    bombY -= 0.5f;
        if (bombY <= 10.0f) {
            exploded = true;
            explosionTimer = 30;
            }
    }

    if (exploded) {
    explosionTimer--;
        if (explosionTimer <= 0) {
        exploded = false;
        bombDropped = false;
        bombY = 45.0f;
            }
    }

    if (bombDropped && !exploded) {
        bombY -= 0.6;
        if (bombY <= -17) {
            exploded = true;
            showShockwave = true;
            explosionVisible = true;
        }
    }

    if (showShockwave && shockwaveRadius < 10) {
        shockwaveRadius += 0.3;
    }

	glutPostRedisplay();

	glutTimerFunc(10, update, 0);
}

void handleMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
	{	speed-=0.05;
			}
    if (button == GLUT_RIGHT_BUTTON)
	{speed+=0.05;   }

	if (button == GLUT_LEFT_BUTTON) {
        if (!bombDropped && !exploded) {
            bombDropped = true;
            bombX = planeMoveX - 6;
            bombY = planeMoveY + 44;
        }
    }

glutPostRedisplay();

}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1330, 700);
	glutCreateWindow("War Project");
	glutDisplayFunc(display);
	gluOrtho2D(-70, 70, -40, 60);
	glutTimerFunc(10, update, 0);
	glutMouseFunc(handleMouse);
	glutMainLoop();
	return 0;
}
