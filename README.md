<!--
*** Thanks for checking out this README Template. If you have a suggestion that would
*** make this better, please fork the repo and create a pull request or simply open
*** an issue with the tag "enhancement".
*** Thanks again! Now go create something AMAZING! :D
***
***
***
*** To avoid retyping too much info. Do a search and replace for the following:
*** github_username, repo_name, twitter_handle, email
-->





<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]


<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/LASERUAVUFPB/Equipe_UAV_Laser">
    <img src="images/logo.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">Fase 1</h3>

  <p align="center">
    YOUR_SHORT_DESCRIPTION
    <br />
    <a href="https://github.com/LASERUAVUFPB/Equipe_UAV_Laser"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/LASERUAVUFPB/Equipe_UAV_Laser">View Demo</a>
    ·
    <a href="https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/issues">Report Bug</a>
    ·
    <a href="https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/issues">Request Feature</a>
  </p>
</p>



<!-- TABLE OF CONTENTS -->
## Table of Contents

* [About the Project](#about-the-project)
  * [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Contact](#contact)
* [Acknowledgements](#acknowledgements)



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](https://example.com)

Here's a blank template to get started:
**To avoid retyping too much info. Do a search and replace with your text editor for the following:**
`LASERUAVUFPB`, `Equipe_UAV_Laser`, `twitter_handle`, `email`


### Built With

* [ROS](www.ros.org)
* [MRS UAV System Installation](https://github.com/ctu-mrs/mrs_uav_system)
* [hector_slam branch nodelet](https://github.com/ctu-mrs/hector_slam)



<!-- GETTING STARTED -->
## Getting Started

To get a local copy up and running follow these simple steps.

### Prerequisites

This is an example of how to list things you need to use the software and how to install them.

1. Go to Instalation on the link above
* [MRS UAV System Installation](https://github.com/ctu-mrs/mrs_uav_system)

2. Inside `mrs_workspace/src`, clone that repo on branch nodelet
```sh
cd ~/mrs_workspace/src
git clone https://github.com/ctu-mrs/hector_slam
```
* [hector_slam branch nodelet](https://github.com/ctu-mrs/hector_slam)

3. Also inside `mrs_workspace/src`, clone petrobras_challenge repo
```sh
cd ~/mrs_workspace/src
git clone https://github.com/LASER-Robotics/Petrobras_Challenge
```

4. Compile mrs_workspace
```sh
cd ~/mrs_workspace
catkin build
```

5. Download zbar lib
```
sudo apt-get install libzbar-dev libzbar0
```


If error appear, change the name of Petrobras_Challenge to petrobras_challenge
and try again or make `catkin clean`.

### Installation

1. Clone the repo inside a `workspace/src` folder
```sh
git clone https://github.com/LASER-Robotics/Equipe_UAV_Laser.git
```

2. Checkout to the working branch
```sh
git checkout feature/working-branch
```

3. Install package
```sh
cd ~/workspace
catkin build
```



<!-- USAGE EXAMPLES -->
## Usage


1- Start the `simulation.sh` that create others terminals to see multiple outputs at the same time, 
so open a new terminal and type:
```sh
./workspace/src/Equipe_UAV_Laser/start/simulation.sh
```

2- On the terminal on folder `one_drone_hector_slam`
```sh
./start.sh
```

3- On the terminal on folder `start`
```sh
./start.sh
```

4- After the simulation is already started, go to terminal on folder `start` and start the panes in that order:

That pane below is responsible to manage the start of the state machine
```
'command_senderUFPB'
```

That pane below is responsible to get all sensor data and the implementation of the state machine
```
'Fase2-Pack'
```
That pane below is responsible to send the command to the `command_senderUFPB`
to start the state machine
```
'search_mode'
```
5- Await for the code execution on pane
```
'Fase2-Pack'
``` 
To see the output at real time.



_For more examples, please refer to the [Documentation](https://example.com)_



<!-- ROADMAP -->
## Roadmap

See the [open issues](https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/issues) for a list of proposed features (and known issues).



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request



<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE` for more information.



<!-- CONTACT -->
## Contact

Lucas Nogueira Nobrega - lucasnnobrega@gmail.com - [![LinkedIn][linkedin-shield]][linkedin-url-lnn]

Cleanderson 

Project Link: [https://github.com/LASERUAVUFPB/Equipe_UAV_Laser](https://github.com/LASERUAVUFPB/Equipe_UAV_Laser)



<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements

* [Welcome to the MRS UAV system](https://ctu-mrs.github.io/)
* [Multi-robot Systems Group](http://mrs.felk.cvut.cz/)



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/LASERUAVUFPB/repo.svg?style=flat-square
[contributors-url]: https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/LASERUAVUFPB/repo.svg?style=flat-square
[forks-url]: https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/network/members
[stars-shield]: https://img.shields.io/github/stars/LASERUAVUFPB/repo.svg?style=flat-square
[stars-url]: https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/stargazers
[issues-shield]: https://img.shields.io/github/issues/LASERUAVUFPB/repo.svg?style=flat-square
[issues-url]: https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/issues
[license-shield]: https://img.shields.io/github/license/LASERUAVUFPB/repo.svg?style=flat-square
[license-url]: https://github.com/LASERUAVUFPB/Equipe_UAV_Laser/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url-lnn]: https://linkedin.com/in/lucasnnobrega
[product-screenshot]: images/screenshot.png


# Example

```cpp
//
// \   /
//  \ /
//   0
//  / \
// /   \
//
```
