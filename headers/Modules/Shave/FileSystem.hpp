//
// FileSystem.hpp for Epil in /home/lucas/Documents/Epitech/Tech3/PFA/epil-ation/headers/Modules/Shave
// 
// Made by Lucas Merlette
// Login   <lucas@epitech.net>
// 
// Started on  Sun Mar  2 17:23:00 2014 Lucas Merlette
// Last update Sun Mar  2 18:06:06 2014 Lucas Merlette
//

#ifndef	EPIL_MODULES_SHAVE_FILESYSTEM_HPP_
# define EPIL_MODULES_SHAVE_FILESYSTEM_HPP_

# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>

namespace shave
{
  struct FileSystem
  {
    static inline bool isfile(std::string const &name)
    {
      struct stat buffer;
      return (stat(name.c_str(), &buffer) == 0);
    }

    static inline bool isdir(std::string const &name)
    {
      struct stat buffer;
      return ((stat(name.c_str(), &buffer) == 0)
	      && (((buffer.st_mode) & S_IFMT) == S_IFDIR));
    }
  };
};

#endif	/* !EPIL_MODULES_SHAVE_FILESYSTEM_HPP_ */
