# Introduction
The goal of this project is to build a simple game, using two fairly simplistic robot arms.
Both of the robot arms will come equipped with a needle at the tip of their arm, and a balloon attached somewhere on their body.
The goal of the game is to pop the other robot arm's balloon.

# Method/Initial concept
The robot arms will be created of small servo motors, icicle sticks, duct tape and a lot of super glue.
Each arm will be controlled by an arduino to which I've connected a basic controller.
The aim is to have the controls be rather simple. A single joystick with the option to press down the stick as if it was a button should suffice.
The stick will be used to position the arm in a 2D plane (X & Y dimensions), perpendicular to the 'direction of stabbing' (Z dimension). 
Pressing down the stick should have the arm lunge forward retaining its approximate XY coordinate, moving smoothly forward in the Z dimension.
Inverse kinematics will be used to convert the 2D coordinate in the plane to actual servo position so that the arm moves into the desired position.

# Process
## Stage 1: Building a simple robot arm that reaches for a coordinate in a 2D plane.
The first step was to create an arm as a proof of concept that moves its tip into a coordinate in a 2D space both to refresh programming concepts and my inverse kinematics knowledge.
Robot arm segments had to be build. For this, I glued two icicle sticks together in a perpendicular and slightly offset fashion and then glued these to the serve themselves.
The picture below should clarify what I mean by this description.
![Robot Arm](https://github.com/rutger-hertoghe/RobotArm-Project/assets/5301949/31ca3a1b-223c-4bf8-b7ac-1c08baf8aec8)

Next I attached whatever this white plastic-y thing is called to the service (which will serve as a base to attach other arm segments to) and screwed a bolt which came with the servo in to secure it.
![ServoBolt](https://github.com/rutger-hertoghe/RobotArm-Project/assets/5301949/06577751-4a9e-46cd-ae8b-35ce538a19e1)

I ended up building a short 2 segment robot arm, created a small structure to provide stability around it and wired it to my arduino.

![2DArm_OnlyArm](https://github.com/rutger-hertoghe/RobotArm-Project/assets/5301949/58076fa9-63f3-487f-840c-1763f19f72db)
![2DArm_FullBuild](https://github.com/rutger-hertoghe/RobotArm-Project/assets/5301949/9e694659-2c0e-4935-893b-7191fed50faf)

