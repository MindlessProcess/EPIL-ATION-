#include  "Epil.hh"
#include  "Action.hh"
#include  "ActionWrite.hh"

void  set_profile(std::string const &id, epil::Epil *epil)
{
  epil::Profile *profile = new epil::Profile();
  profile->setId(id);

  // creating an ActionWrite --------------------
  epil::ActionWrite *wr_action = new epil::ActionWrite("wr_action");
  std::pair<int, int> my_dst_pair[] =
    {
      std::make_pair(5, 10),
      std::make_pair(10, 26),
      std::make_pair(28, 29)
    };
  wr_action->wr_setElem(epil::filetype::DST, 
			"misc/dst_file.txt", 
			new epil::BlockList(std::list<std::pair<int, int> >(my_dst_pair, my_dst_pair + sizeof(my_dst_pair) / sizeof(std::pair<int, int>))));

  std::pair<int, int> my_src_pair[] =
    {
      std::make_pair(3, 6),
      std::make_pair(11, 22),
      std::make_pair(24, 24)
    };
  wr_action->wr_setElem(epil::filetype::SRC, "misc/src_file.txt", new epil::BlockList(std::list<std::pair<int, int> >(my_src_pair, my_src_pair + sizeof(my_src_pair) / sizeof(std::pair<int, int>))));
  profile->setAction(wr_action);

  // creating another ActionWrite ---------------
  // epil::ActionWrite *wr_action_bis = new epil::ActionWrite("wr_action_bis");
  // wr_action_bis->wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)));
  // wr_action_bis->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  // profile->setAction(wr_action_bis);

  // // creating another ActionWrite ---------------
  // epil::ActionWrite *wr_action_ter = new epil::ActionWrite("wr_action_ter");
  // wr_action_ter->wr_setDst("misc/dst_file.c", new epil::BlockList(std::make_pair(1, 8)));
  // wr_action_ter->wr_setSrc("misc/src_file.c", new epil::BlockList(std::make_pair(3, 5)));
  // profile->setAction(wr_action_ter);

  epil::utils::Console::log("Action = <");
  for (std::list<epil::Action*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
    {
      epil::utils::Console::log((*it)->getId());
      if (it != profile->getActionList().end() && (it != --profile->getActionList().end()))
	epil::utils::Console::log(", ");
    }
  epil::utils::Console::nlog(">");
  profile->changeActionOrder("wr_action", "wr_action_bis");
  epil::utils::Console::nlog("Action order changed");
  // profile->revertActionOrder();
  // epil::utils::Console::nlog("Action order reversed");
  epil::utils::Console::log("Action = <");
  for (std::list<epil::Action*>::iterator it = profile->getActionList().begin(); it != profile->getActionList().end(); ++it)
    {
      epil::utils::Console::log((*it)->getId());
      if (it != profile->getActionList().end() && (it != --profile->getActionList().end()))
	epil::utils::Console::log(", ");
    }
  epil::utils::Console::nlog(">");
  epil::utils::Console::nlog("");
  // std::cout << "End of printing actions" << std::endl;
  epil->loadProfile(profile);
}

int	main()
{
  // Unit tests on Profile.hh
  {
    epil::Epil  *epil = new epil::Epil();
    set_profile("SIGSEV", epil);
    // set_profile("SIGERR", epil);
    // set_profile("SIGHANDLER", epil);
    // set_profile("SIGSEV", epil);
    // set_profile("SIGFALSE", epil);
    // set_profile("SIGSEV", epil);
    epil->useProfile("SIGSEV");
  }
  return (0);
}
