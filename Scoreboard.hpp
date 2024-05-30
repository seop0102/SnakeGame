#pragma once


class Scoreboard {
  WINDOW *score_win;
  // bool length_goal_achieved;
  // bool apple_goal_achieved;
  // bool grape_goal_achieved;
  // bool gate_goal_achieved;
  int goal[4] = {7,3,1,1};


public:
  Scoreboard() {


  }


  Scoreboard(int width, int y, int x) {
    score_win = newwin(5, width, y, x);
  }




  void initialize(int initial_score) {
    // length_goal_achieved = true;
    // apple_goal_achieved = false;
    // grape_goal_achieved = false;
    // gate_goal_achieved = false;


    clear();
    mvwprintw(score_win, 0, 0, "Score");
    mvwprintw(score_win, 1, 0, "B : ");
    mvwprintw(score_win, 2, 0, "+ : ");
    mvwprintw(score_win, 3, 0, "- : ");
    mvwprintw(score_win, 4, 0, "G : ");
    updateScore(initial_score, 4, 0, 0);
    refresh();
  }




  void updateScore(int score, int length, int apple_cnt, int grape_cnt) {
    mvwprintw(score_win, 0, score_win->_maxx - 20, "%01d", score);


    if (length >= goal[0]) mvwprintw(score_win, 1, score_win->_maxx - 20, "%d / 7 ( V )", length);
    else mvwprintw(score_win, 1, score_win->_maxx - 20, "%d / 7 (   )", length);


    if (apple_cnt >= goal[1]) mvwprintw(score_win, 2, score_win->_maxx - 20, "%d / 3 ( V )", apple_cnt);
    else mvwprintw(score_win, 2, score_win->_maxx - 20, "%d / 3 (   )", apple_cnt);


    if (grape_cnt >= goal[2]) mvwprintw(score_win, 3, score_win->_maxx - 20, "%d / 1 ( V )", grape_cnt);
    else mvwprintw(score_win, 3, score_win->_maxx - 20, "%d / 1 (   )", grape_cnt);


    if (grape_cnt >= goal[3]) mvwprintw(score_win, 4, score_win->_maxx - 20, "%d / 1 ( V )", grape_cnt);
    else mvwprintw(score_win, 4, score_win->_maxx - 20, "%d / 1 (   )", grape_cnt);
   
    refresh();
  }


  // void setLengthGoalAchieved(bool achieved) {
  //  length_goal_achieved = achieved;
  // }


  // void setAppleGoalAchieved(bool achieved) {
  //  apple_goal_achieved = achieved;
  // }


  // void setGrapeGoalAchieved(bool achieved) {
  //  grape_goal_achieved = achieved;
  // }


  // void setGateGoalAchieved(bool achieved) {
  //  gate_goal_achieved = achieved;
  // }


  void clear() {
    wclear(score_win);
  }


  void refresh() {
    wrefresh(score_win);
  }
};
