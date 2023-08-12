# OpenGL Stuff
Repository containing small, shared OpenGL projects each used to explore features of OpenGL. Each OpenGL project is stored directly within the repository's root folder.

## Setup
1. Clone the repository (with **submodules**) to your Eclipse workspace. The path to this README.md file should be: `path/to/Workspace/opengl-stuff/README.md`.
2. Then add the `opengl-utils` library (located at `opengl-stuff/Libraries/opengl-utils`) as an Eclipse project.
   
   *This project is an Eclipse C/C++ library project, and it contains library code used by the exploratory projects in this repository. Add this project first so that Eclipse will recognize it when you add the other projects.*
   1. To add `opengl-utils`, go to Eclipse and go to `File` --> `Open Projects from File System...`
      ![image](https://github.com/Palanath/opengl-stuff/assets/117754232/fe48a46a-e41c-4664-affb-a6a5cea6c659)
   2. Then import the `opengl-utils` project: ![image](https://github.com/Palanath/opengl-stuff/assets/117754232/2c5e6b95-c0a8-4709-8110-659444c36146)
      and hit `Finish`.

      *If your C++ build toolchain/environment is set up as the repository expects, you should already be able to build `opengl-utils` at this point. You can try expanding the `opengl-utils` project and then selecting or opening the `GLUtils.cpp` file, then at the top of Eclipse, going to `Project` --> `Build`. If there are no errors in the console, it has built successfully.*
3. Now you can add the OpenGL projects at the root of the repository. For example, if you want to add the `instanced-rendering` project:
   1. Go to `File` --> `Open Projects from File System...`
   2. In the file path at the top, you can put the path for this repository: `path/to/Workspace/opengl-stuff/`.
   3. Make sure the **Search for nested projects** checkbox is checked. (This may not actually be necessary.)
   4. Select the projects you want to add. You can select `opengl-stuff\instanced-rendering` for example.
   5. Hit the `Finish` button at the bottom. The project should be imported and everything should be configured.
4. Make sure the projects are not *closed*. If they are, you won't see a drop-down arrow next to them:
   ![image](https://github.com/Palanath/opengl-stuff/assets/117754232/def1ae82-98fe-4a32-bd11-ed7826a9b609)
   *In this image, `Instanced Rendering` is closed.* Double click on any closed projects to open them.
5. Finally, try building the `Instanced Rendering` project. Expand it, go to the `src` folder, then select or open the `Instanced Rendering.cpp` file.
6. Click on `Project` --> `Build` at the top of Eclipse. This will also build the `opengl-utils` project, since that is referenced as a dependency.
7. You should be able to run the project. You may need to click on the project in the Project Explorer to select it (select the project itself, not the C++ source file) before the run button actually tries to run it. You can hover over the run button at the top of Eclipse to see what project/file it will try running when you click on it.

   ![image](https://github.com/Palanath/opengl-stuff/assets/117754232/1a71a366-2d79-45a0-969a-0b5afd0317a2)

## Creating Projects
To create a project, simply make the C/C++ project within the repository root, then add the project files to the repository through a git commit. The repository's `.gitignore` is set up to ignore the `.settings/language.settings.xml` file and any `.prefs` files contained within the `.settings` folder of any Eclipse project at the root of the repository, since these often contain platform/environment-specific information that is not necessary to build the project or import and execute it.

The `.project` and `.cproject` files *are* included in the repository. These contain information about dependency/reference configuration and how to build the project.
