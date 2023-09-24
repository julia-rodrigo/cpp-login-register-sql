#include "LoginForm.h";
#include "Dashboard.h"
#include "RegisterForm.h"

using namespace System;
using namespace System::Windows::Forms;

void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	User^ user = nullptr;
	while (true) {
		RestuarantProject::LoginForm loginForm;
		loginForm.ShowDialog();

		if (loginForm.switchToRegister) {
			RestuarantProject::RegisterForm registerForm;
			registerForm.ShowDialog();

			if (registerForm.switchToLogin) {
				continue; // go back to the begining of the while loop
			}
			else {
				user = registerForm.user;
				break;
			}

		}
		else {
			user = loginForm.user;
			break;
		}
	}


	if (user != nullptr) {
		RestuarantProject::Dashboard dashboard(user);
		Application::Run(% dashboard);
	}
	else {
		MessageBox::Show(
			"Authentication Cancelled",
			"Program.cpp",
			MessageBoxButtons::OK
		);
	}
}